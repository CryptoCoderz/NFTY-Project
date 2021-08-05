NFTY [NFTY] 2020
===========================================================================================

What is the NFTY [NFTY] Blockchain?
-----------------------------------------

### Overview
The NFTY Portal ecosystem will be the ‘gold standard’ of this exciting and rapidly developing blockchain space and will become the benchmark or reference point for future decentralized exchanges or ‘Portals’. Maintained by our dynamic block system, the extremely low fees for transactions and NFT minting on the NFTY blockchain will provide a costeffective solution to current standards. The universal NFTY chain allows for minted works to be available on all marketplaces across any chain adding efficiency to current protocols. Our ability to store data on-chain will have numerous positive effects on the industry providing a much needed high level of Safety, increased Efficiency and overall allowing blockchain to operate more Effectively #SEE. All operations, from trading to minting will be conveniently executed in the safe and powerful, decentralized environment of our revolutionary, proprietary NFTY Portal. Our vision for NFTY and the NFTY Portal Project’s ultimate goal is to release a decentralized exchange that will allow users to trade NFTs, coins and tokens all from one decentralized exchange, ‘NFTY Portal’, in a safe and secure environment offering cross-chain, multi-chain, atomic swap and peer-to-peer transactions. Access to the massive liquidity pools on but not limited to ETH and BSC-based swaps will be available to users through a wrapped NFTY Space coin. Users will also be able to create Liquidity Pools within the NFTY Portal.

### Blockchain Technology
Blockchain technology has the capabilities to change a variety of things in the world and can also be the backbone of a new internet. One place that blockchain technology has not had an impact on yet is website on the blockchain. However, NFTY is trying to change that and is well on their way to doing so.

### Fractal multi-chain platform
Seeing our vision through to completion we are in final build phases of what we have coined the "Fractal" platform. This platform is service layer that handles a infinitely layered network of dynamic side-chains and mini-chains in order to provide the ability to host dynamic data in a very fast, scalable and decentralized manner using the X-Node system as its host layer and utilizing the mainnet as a verification system for launching NFTs, Tokens or other hosted material. By doing this we avoid bloat, and mainnet net reliance beyond launch needs. Ultimately this platform can replace the need for servers, DNS hosting and much more while offering a much more robust solution than available today. I guess, you could call it Web3 or the "internet computer" as some have thrown the term around.

### NFT (Non-fungible Token)
Introducing altcoins to NFTs, as of v1.0.0.3 prototype now features NFT capabilities. This offers the ability to artists, musicians and animators alike a unified place to store, encrypt, protect, sell and share their artwork! Current compatible formats are JPG/JPEG, PNG, GIF (Animation), OGG VORBIS (Audio) in a square format for initial testing for pictures/animation and up to 5 minute sound files for OGG VORBIS audio. This is a soft limit done only for initial testing. These limits will soon be lifted for full release in future versions.

### Tokens (Like ETH)
Along with NFTs we have adapted the technology in the Fractal platform to launch and manage Tokens! No longer are there only the few giants that can do this, launch your own Token using NFTY as "GAS" and for no where near the fees!

### BVAC (Bits Visualized As Color)
BVAC is a unique system that we developed and created in house just for Espers [ESP] and associated projects such as NFTY. This offers us the ability to store ANY data as a PNG or JPG, similarly to a QR code, with only three files being required as apposed to three entire libraries that QR codes require and the data storage is denser. If you would like to learn more about this feature feel free to reach out to CryptoCoderz or SaltineChips. The current proof of concept implementation is the ability to store and read a public receiving address as a 16x16 BVAC image. Users can share their public keys this way by simply sending each other the BVAC image of the pubkey created from the wallet and then the receiving part is able to load the image using the wallet and decode it into the pubkey once again.

### Secured Messaging
Developing the usability features: The secured messaging system, masternodes (intuitive node launching and monitoring), smooth sync patch, shrinking blockchain, light clients and much much more.

### Custom Difficulty Retarget Algorithm “VRX”
VRX is designed from the ground up to integrate properly with the Velocity parameter enforcement system to ensure users no longer receive orphan blocks. In addition to this function it also dynamicaly adjusts for fluctuations in hashrate or staking whether it be great or small. Being a "Hybrid" blockchain, NFTY also utilizes VRX's advanced block shuffling and difficulty skewing proceedures in order to offer a truly equal mining/staking experience while further increasing the network's security and reliability. 

### Velocity Block Constraint System
Ensuring NFTY stays as secure and robust as possible the CryptoCoderz team have implemented what's known as the Velocity block constraint system. This system acts as third and final check for both mined and peer-accepted blocks ensuring that all parameters are strictly enforced.

### Wish (bmw512) Proof-of-Work Algorithm
Wish or bmw512 hashing algorithm is utilized for the Proof-of-Work function and also replaces much of the underlying codebase hashing functions as well that normally are SHA256. By doing so this codebase is able to be both exponentially lighter and more secure in comparison to reference implementations.

Specifications and General info
------------------
NFTY uses 

	libsecp256k1,
	libgmp,
	Boost1.68, OR Boost1.58,  
	Openssl1.02r,
	Berkeley DB 6.2.32,
	QT5.12.1,
	to compile


General Specs

	Block Spacing: 5 Minutes
	Stake Minimum Age: 80 Confirmations (PoS-v3) | 6 Hours (PoS-v2)
	Port: 20021
	RPC Port: 19697


BUILD LINUX
-----------
### Compiling NFTY "SatoshiCore" daemon on Ubunutu 18.04 LTS Bionic
### Note: guide should be compatible with other Ubuntu versions from 14.04+

### Become poweruser
```
sudo -i
```
### CREATE SWAP FILE FOR DAEMON BUILD (if system has less than 2GB of RAM)
```
cd ~; sudo fallocate -l 3G /swapfile; ls -lh /swapfile; sudo chmod 600 /swapfile; ls -lh /swapfile; sudo mkswap /swapfile; sudo swapon /swapfile; sudo swapon --show; sudo cp /etc/fstab /etc/fstab.bak; echo '/swapfile none swap sw 0 0' | sudo tee -a /etc/fstab
```

### Dependencies install
```
cd ~; sudo apt-get install -y ntp git build-essential libssl-dev libdb-dev libdb++-dev libboost-all-dev libqrencode-dev libcurl4-openssl-dev curl libzip-dev; apt-get update -y; apt-get install -y git make automake build-essential libboost-all-dev; apt-get install -y yasm binutils libcurl4-openssl-dev openssl libssl-dev; sudo apt-get install -y libgmp-dev; sudo apt-get install -y libtool;
```

### Dependencies build and link
```
cd ~; wget http://download.oracle.com/berkeley-db/db-6.2.32.NC.tar.gz; tar zxf db-6.2.32.NC.tar.gz; cd db-6.2.32.NC/build_unix; ../dist/configure --enable-cxx --disable-shared; make; sudo make install; sudo ln -s /usr/local/BerkeleyDB.6.2/lib/libdb-6.2.so /usr/lib/libdb-6.2.so; sudo ln -s /usr/local/BerkeleyDB.6.2/lib/libdb_cxx-6.2.so /usr/lib/libdb_cxx-6.2.so; export BDB_INCLUDE_PATH="/usr/local/BerkeleyDB.6.2/include"; export BDB_LIB_PATH="/usr/local/BerkeleyDB.6.2/lib"
```

### GitHub pull (Source Download)
```
cd ~; git clone https://github.com/CryptoCoderz/NFTY NFTY
```

### Build NFTY daemon
```
cd ~; cd ~/NFTY/src; chmod a+x obj; chmod a+x leveldb/build_detect_platform; chmod a+x secp256k1; chmod a+x leveldb; chmod a+x ~/NFTY/src; chmod a+x ~/NFTY; make -f makefile.unix USE_UPNP=-; cd ~; cp -r ~/NFTY/src/NFTYd /usr/local/bin/NFTYd;
```

### (Optional) Build NFTY-QT (GUI wallet) on Linux 

**All previous steps must be completed first.**

If you recompiling some other time you don't have to repeat previous steps, but need to define those variables. Skip this command if this is your first build and previous steps were performed in current terminal session.
```
export BDB_INCLUDE_PATH="/usr/local/BerkeleyDB.6.2/include"; export BDB_LIB_PATH="/usr/local/BerkeleyDB.6.2/lib"
```

With UPNP:

```
cd ~; cd ~/NFTY; qmake -qt=qt5; make
```

**Recommended Without** UPNP:

```
cd ~; cd ~/NFTY; qmake -qt=qt5 USE_UPNP=-; make
```



### Create config file for daemon
```
cd ~; sudo ufw allow 20047/tcp; sudo ufw allow 19657/tcp; sudo ufw allow 22/tcp; sudo mkdir ~/.NFTY; cat << "CONFIG" >> ~/.NFTY/NFTY.conf
listen=1
server=1
daemon=1
testnet=0
rpcuser=NFTYrpcuser
rpcpassword=SomeCrazyVeryVerySecurePasswordHere
rpcport=19657
port=20047
rpcconnect=127.0.0.1
rpcallowip=127.0.0.1
addnode=46.101.103.207:20047
CONFIG
chmod 700 ~/.NFTY/NFTY.conf; chmod 700 ~/.NFTY; ls -la ~/.NFTY
```

### Run NFTY daemon
```
cd ~; NFTYd; NFTYd getinfo
```

### Troubleshooting
### for basic troubleshooting run the following commands when compiling:
### this is for minupnpc errors compiling

```
make clean -f makefile.unix USE_UPNP=-
make -f makefile.unix USE_UPNP=-
```
### Updating daemon in bin directory
```
cd ~; cp -r ~/NFTY/src/NFTYd /usr/local/bin
```

License
-------

NFTY [NFTY] is released under the terms of the MIT license. See [COPYING](COPYING) for more
information or see https://opensource.org/licenses/MIT.

Development Process
-------------------

The `master` branch is regularly built and tested, but is not guaranteed to be
completely stable. [Tags](https://github.com/SaltineChips/NFTY/Tags) are created
regularly to indicate new official, stable release versions of NFTY [NFTY].

The contribution workflow is described in [CONTRIBUTING.md](CONTRIBUTING.md).

The developer [mailing list](https://lists.linuxfoundation.org/mailman/listinfo/bitcoin-dev)
should be used to discuss complicated or controversial changes before working
on a patch set.

Developer Discord can be found at https://discord.gg/Jp2ujYH.

Testing
-------

Testing and code review is the bottleneck for development; we get more pull
requests than we can review and test on short notice. Please be patient and help out by testing
other people's pull requests, and remember this is a security-critical project where any mistake might cost people
lots of money.

### Automated Testing

Developers are strongly encouraged to write [unit tests](/doc/unit-tests.md) for new code, and to
submit new unit tests for old code. Unit tests can be compiled and run
(assuming they weren't disabled in configure) with: `make check`

There are also [regression and integration tests](/qa) of the RPC interface, written
in Python, that are run automatically on the build server.

### Manual Quality Assurance (QA) Testing

Changes should be tested by somebody other than the developer who wrote the
code. This is especially important for large or high-risk changes. It is useful
to add a test plan to the pull request description if testing the changes is
not straightforward.
