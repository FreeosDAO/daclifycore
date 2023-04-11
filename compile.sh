# compile the test version first and rename daclifycore.abi to daclifycore_testnet.abi
# this step is necessary because the --abigen_output flag appears not to do anything in eosio.cdt v1.8
echo "Compiling Testnet version"
eosio-cpp --abigen src/daclifycore.cpp -Iinclude --contract=daclifycore -o daclifycore_testnet.wasm
cp daclifycore.abi daclifycore_testnet.abi

# compile the production version
echo "Compiling Production version"
eosio-cpp --abigen src/daclifycore.cpp -DPRODUCTION -Iinclude --contract=daclifycore -o daclifycore.wasm
