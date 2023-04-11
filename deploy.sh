name=$1

if [[ -n "$name" ]]; then
    cleos -u https://proton.testnet.protonuk.io set contract $1 ~/contracts/daclifycore daclifycore_testnet.wasm daclifycore_testnet.abi
else
    echo "argument error - first argument is the contract name"
fi

