echo "Compiling Testnet version"
eosio-cpp --abigen src/daclifycore.cpp -Iinclude --contract=daclifycore -o daclifycore_testnet.wasm
cp daclifycore.abi daclifycore_testnet.abi
