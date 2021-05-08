// Copyright (c) 2010 Satoshi Nakamoto
// Copyright (c) 2009-2012 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "assert.h"

#include "chainparams.h"
#include "main.h"
#include "util.h"
// TODO: Verify the requirement of below link
// #include "base58.h"

#include <boost/assign/list_of.hpp>

using namespace boost::assign;

struct SeedSpec6 {
    uint8_t addr[16];
    uint16_t port;
};

#include "chainparamsseeds.h"

// Convert the pnSeeds6 array into usable address objects.
static void convertSeed6(std::vector<CAddress> &vSeedsOut, const SeedSpec6 *data, unsigned int count)
{
    // It'll only connect to one or two seed nodes because once it connects,
    // it'll get a pile of addresses with newer timestamps.
    // Seed nodes are given a random 'last seen time' of between one and two
    // weeks ago.
    const int64_t nOneWeek = 7*24*60*60;
    for (unsigned int i = 0; i < count; i++)
    {
        struct in6_addr ip;
        memcpy(&ip, data[i].addr, sizeof(ip));
        CAddress addr(CService(ip, data[i].port));
        addr.nTime = GetTime() - GetRand(nOneWeek) - nOneWeek;
        vSeedsOut.push_back(addr);
    }
}

//
// Main network
//
class CMainParams : public CChainParams {
public:
    CMainParams() {
        // The message start string is designed to be unlikely to occur in normal data.
        // The characters are rarely used upper ASCII, not valid as UTF-8, and produce
        // a large 4-byte int at any alignment.
        pchMessageStart[0] = 0xc3;
        pchMessageStart[1] = 0x34;
        pchMessageStart[2] = 0xa1;
        pchMessageStart[3] = 0xf9;
        vAlertPubKey = ParseHex("09a84535a489f996be6b659c91a56897ebeb5d456698712acdbef7894452f81f85d131aadfef3be6145678454852a2d08c6314bba5ca3cbe5616262da3b1a6afed");
        nDefaultPort = 20047; //
        nRPCPort = 19657; //
        bnProofOfWorkLimit = CBigNum(~uint256(0) >> 14);
        bnProofOfStakeLimit = CBigNum(~uint256(0) >> 16);

        const char* pszTimestamp = "New ransomware taskforce report published, how to disrupt ransomware and reduce effects of attacks | Mark | April 29, 2021 Security | The Merkle";
        std::vector<CTxIn> vin;
        vin.resize(1);
        vin[0].scriptSig = CScript() << 0 << CBigNum(42) << vector<unsigned char>((const unsigned char*)pszTimestamp, (const unsigned char*)pszTimestamp + strlen(pszTimestamp));
        std::vector<CTxOut> vout;
        vout.resize(1);
        vout[0].nValue = 1 * COIN;
        vout[0].SetEmpty();
        CTransaction txNew(1, timeGenesisBlock, vin, vout, 0);
        genesis.vtx.push_back(txNew);
        genesis.hashPrevBlock = 0;
        genesis.hashMerkleRoot = genesis.BuildMerkleTree();
        genesis.nVersion = 1;
        genesis.nTime    = timeGenesisBlock;
        genesis.nBits    = bnProofOfWorkLimit.GetCompact();
        genesis.nNonce   = 4021;

        /** Genesis Block MainNet */
        /*
Hashed MainNet Genesis Block Output
block.hashMerkleRoot == 94a0584a67aa8b56a7da7f03f4cb0bfd5d0ce23505b1d8753999982a19567e77
block.nTime = 1604318400
block.nNonce = 4021
block.GetHash = 0000e2d11e957f62868ac8a9f7f6d7331cc0fbab05f6dd47afb083c792b5692c
        */

        hashGenesisBlock = genesis.GetHash();
        assert(hashGenesisBlock == uint256("0x0000e2d11e957f62868ac8a9f7f6d7331cc0fbab05f6dd47afb083c792b5692c"));
        assert(genesis.hashMerkleRoot == uint256("0x94a0584a67aa8b56a7da7f03f4cb0bfd5d0ce23505b1d8753999982a19567e77"));

        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1,53);
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1,23);
        base58Prefixes[SECRET_KEY] =     std::vector<unsigned char>(1,32);
        base58Prefixes[STEALTH_ADDRESS] = std::vector<unsigned char>(1,34);
        base58Prefixes[EXT_PUBLIC_KEY] = list_of(0x04)(0x88)(0xB2)(0x1E).convert_to_container<std::vector<unsigned char> >();
        base58Prefixes[EXT_SECRET_KEY] = list_of(0x04)(0x88)(0xAD)(0xE4).convert_to_container<std::vector<unsigned char> >();

        // vSeeds.push_back(CDNSSeedData("node0",  "000.000.000.000"));


        convertSeed6(vFixedSeeds, pnSeed6_main, ARRAYLEN(pnSeed6_main));

        nPoolMaxTransactions = 9;
        strMNenginePoolDummyAddress = "NPArwtQcsuLPkN6qmsRYNobiw8xPDBLguV";
        strDevOpsAddress = "NP1dCbQQTCeAomXcU8RyzamMySVw9dfBWY";
        nEndPoWBlock = 10000;
        nStartPoSBlock = 1;
    }

    virtual const CBlock& GenesisBlock() const { return genesis; }
    virtual Network NetworkID() const { return CChainParams::MAIN; }

    virtual const vector<CAddress>& FixedSeeds() const {
        return vFixedSeeds;
    }
protected:
    CBlock genesis;
    vector<CAddress> vFixedSeeds;
};
static CMainParams mainParams;


//
// Testnet
//
class CTestNetParams : public CMainParams {
public:
    CTestNetParams() {
        // The message start string is designed to be unlikely to occur in normal data.
        // The characters are rarely used upper ASCII, not valid as UTF-8, and produce
        // a large 4-byte int at any alignment.
        pchMessageStart[0] = 0xc9;
        pchMessageStart[1] = 0x11;
        pchMessageStart[2] = 0xe1;
        pchMessageStart[3] = 0xf7;
        bnProofOfWorkLimit = CBigNum(~uint256(0) >> 12);
        bnProofOfStakeLimit = CBigNum(~uint256(0) >> 14);
        vAlertPubKey = ParseHex("00a98456af9f1996be6b456321a94fbfebeb5d517648afbacdbef4d2f7c2f81f85d131a669df3be6113afd454852a2d08c6314bba5ca3cbe5616262da3b1a6afed");
        nDefaultPort = 19877; //
        nRPCPort = 19991;
        strDataDir = "testnet";

        // Modify the testnet genesis block so the timestamp is valid for a later start.
        genesis.nTime  = timeTestNetGenesis;
        genesis.nBits  = bnProofOfWorkLimit.GetCompact();
        genesis.nNonce = 6164;

        /** Genesis Block TestNet */
        /*
Hashed TestNet Genesis Block Output
block.hashMerkleRoot == 94a0584a67aa8b56a7da7f03f4cb0bfd5d0ce23505b1d8753999982a19567e77
block.nTime = 1604318430
block.nNonce = 6164
block.GetHash = 000b64b0aaf6c68690447efb641b39003e57d8a89271874744e152e2dbe4918f
        */

        hashGenesisBlock = genesis.GetHash();
        assert(hashGenesisBlock == uint256("0x000b64b0aaf6c68690447efb641b39003e57d8a89271874744e152e2dbe4918f"));

        vFixedSeeds.clear();
        vSeeds.clear();

        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1,66);
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1,55);
        base58Prefixes[SECRET_KEY] =     std::vector<unsigned char>(1,77);
        base58Prefixes[STEALTH_ADDRESS] = std::vector<unsigned char>(1,16);
        base58Prefixes[EXT_PUBLIC_KEY] = list_of(0x04)(0x35)(0x87)(0xCF).convert_to_container<std::vector<unsigned char> >();
        base58Prefixes[EXT_SECRET_KEY] = list_of(0x04)(0x35)(0x83)(0x94).convert_to_container<std::vector<unsigned char> >();

        nEndPoWBlock = 0x7fffffff;
    }
    virtual Network NetworkID() const { return CChainParams::TESTNET; }
};
static CTestNetParams testNetParams;

//
// Regression test
//
class CRegTestParams : public CTestNetParams {
public:
    CRegTestParams() {
        pchMessageStart[0] = 0xc8;
        pchMessageStart[1] = 0x36;
        pchMessageStart[2] = 0xf1;
        pchMessageStart[3] = 0xa3;
        bnProofOfWorkLimit = CBigNum(~uint256(0) >> 1);
        genesis.nTime = timeRegNetGenesis;
        genesis.nBits  = bnProofOfWorkLimit.GetCompact();
        genesis.nNonce = 8;
        hashGenesisBlock = genesis.GetHash();
        nDefaultPort = 19629; // John F. Kennedy's Moon Speech
        strDataDir = "regtest";

        /** Genesis Block RegNet */
        /*
Hashed RegNet Genesis Block Output
block.hashMerkleRoot == 94a0584a67aa8b56a7da7f03f4cb0bfd5d0ce23505b1d8753999982a19567e77
block.nTime = 1604318490
block.nNonce = 8
block.GetHash = e9d59074afd327d443b1e1b00dc0b37366a5d32113f893531b0c90280e3ee928
        */

        assert(hashGenesisBlock == uint256("0xe9d59074afd327d443b1e1b00dc0b37366a5d32113f893531b0c90280e3ee928"));

        vSeeds.clear();  // Regtest mode doesn't have any DNS seeds.
    }

    virtual bool RequireRPCPassword() const { return false; }
    virtual Network NetworkID() const { return CChainParams::REGTEST; }
};
static CRegTestParams regTestParams;

static CChainParams *pCurrentParams = &mainParams;

const CChainParams &Params() {
    return *pCurrentParams;
}

void SelectParams(CChainParams::Network network) {
    switch (network) {
        case CChainParams::MAIN:
            pCurrentParams = &mainParams;
            break;
        case CChainParams::TESTNET:
            pCurrentParams = &testNetParams;
            break;
        case CChainParams::REGTEST:
            pCurrentParams = &regTestParams;
            break;
        default:
            assert(false && "Unimplemented network");
            return;
    }
}

bool SelectParamsFromCommandLine() {
    bool fRegTest = GetBoolArg("-regtest", false);
    bool fTestNet = GetBoolArg("-testnet", false);

    if (fTestNet && fRegTest) {
        return false;
    }

    if (fRegTest) {
        SelectParams(CChainParams::REGTEST);
    } else if (fTestNet) {
        SelectParams(CChainParams::TESTNET);
    } else {
        SelectParams(CChainParams::MAIN);
    }
    return true;
}
