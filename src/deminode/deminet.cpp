// Copyright (c) 2021 The Espers Project/CryptoCoderz Team
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "deminet.h"

// TODO: Open deminode.conf and scan for registered Demi-nodes
// For now we hardset Team nodes as Demi-nodes
std::string scanDeminodes[5] {
    "80.211.102.238:22448", "80.211.27.133:22448", "134.122.23.191:22448", "159.89.114.40:22448",
    "127.0.0.1"
};
// Setup Demi network voting log
int voteDeminodes[4] {
    0, 0, 0, 0
};
// Setup stored Demi node heights/hashes
int heightDeminodes[4] {
    0, 0, 0, 0
};
uint256 hashDeminodes[4] {
    0, 0, 0, 0
};

bool fDemiFound = false;

bool fDemiPeerRelay(std::string peerAddr)
{
    int l = 0;
    // Loop through Demi-node list
    while(l == 0) {
        if(peerAddr == scanDeminodes[l]) {
            // Success if found
            LogPrintf("Demi-node System: fDemiPeerRelay - Peer: %s matches listed Demi-node!\n", peerAddr);
            return true;
        }
        // Move up in loop count
        l++;
    }
    // Failure if not found
    LogPrintf("Demi-node System: fDemiPeerRelay - Peer: %s does NOT match any listed Demi-node!\n", peerAddr);
    return false;
}

static void DemiNodeFetch(uint256 blockHash)
{
        LOCK(cs_vNodes);
        // block allocation
        vector<CInv> vGetDemiData;
        const CInv& dinv = CInv(MSG_DEMIBLOCK, blockHash);
        vGetDemiData.push_back(dinv);
        // Reset previously set data
        fDemiFound = false;
        // Loop through peers/nodes
        BOOST_FOREACH(CNode* pnode, vNodes) {
            // Skip obsolete nodes
            if(pnode->nVersion < DEMINODE_VERSION) {
                continue;
            }

            // See if we found a Demi-node
            if(scanDeminodes[0] == pnode->addrName) {
                voteDeminodes[0] ++;
                pnode->PushMessage("getdata", vGetDemiData);
                fDemiFound = true;
            } else if(scanDeminodes[1] == pnode->addrName) {
                voteDeminodes[1] ++;
                pnode->PushMessage("getdata", vGetDemiData);
                fDemiFound = true;
            } else if(scanDeminodes[2] == pnode->addrName) {
                voteDeminodes[2] ++;
                pnode->PushMessage("getdata", vGetDemiData);
                fDemiFound = true;
            } else if(scanDeminodes[3] == pnode->addrName) {
                voteDeminodes[3] ++;
                pnode->PushMessage("getdata", vGetDemiData);
                fDemiFound = true;
            }
        }

        vGetDemiData.clear();
        if(fDemiFound) {
            LogPrintf("Demi-node System: DemiNodeFetch - Requested data successfully!\n");
        }
}

bool getDemiBlock(uint256 blockHash)
{
    // Fetch block data from Demi-nodes
    DemiNodeFetch(blockHash);

    // Setup our node list to scan through
    //
    // TODO: Open deminode.conf and scan for registered Demi-nodes
    // For now we hardset Team nodes as Demi-nodes
    //
    //std::string scanNet[vNodes.size()];

    // Make sure we found a Demi-node
    if(!fDemiFound) {
        LogPrintf("Demi-node System: WARNING - No Demi-nodes found!\n");
        return false;
    }

    // Report success if we reach this point
    return true;
}
