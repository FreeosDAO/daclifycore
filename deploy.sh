if [[ -n $1 ]]
 then
    cleos -u https://proton.testnet.protonuk.io set contract $1 ~/contracts/daoscapecore daoscapecore_testnet.wasm daoscapecore_testnet.abi
else
    echo "error - first argument is the contract name"
fi

