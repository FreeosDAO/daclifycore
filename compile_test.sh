echo "Compiling Testnet version"
eosio-cpp --abigen src/daclifycore.cpp -Iinclude --contract=daclifycore -o daoscapecore_testnet.wasm
cp daoscapecore.abi daoscapecore_testnet.abi
