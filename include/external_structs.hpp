
    struct actionhooks {
      uint64_t hook_id;
      eosio::name hooked_action;// must be the action name on which to apply the hook
      eosio::name hooked_contract;// must be the contract where the hooked_action is
      eosio::name hook_action_name;
      std::string description;
      uint64_t exec_count;
      eosio::time_point_sec last_exec;
      bool enabled;
      auto primary_key() const { return hook_id; }
      uint128_t by_hook() const { return (uint128_t{hooked_action.value} << 64) | hooked_contract.value; }

    };
    typedef eosio::multi_index<eosio::name("actionhooks"), actionhooks,
      eosio::indexed_by<"byhook"_n, eosio::const_mem_fun<actionhooks, uint128_t, &actionhooks::by_hook>>
    > actionhooks_table;

  
  struct kyc_prov {
    eosio::name kyc_provider;
    std::string kyc_level;
    uint64_t kyc_date;
  };
  
  struct[[ eosio::table("usersinfo"), eosio::contract("eosio.proton") ]] userinfo {
    eosio::name acc;
    std::string name;
    std::string avatar;
    bool verified;
    uint64_t date;
    uint64_t verifiedon;
    eosio::name verifier;

    std::vector<eosio::name> raccs;
    std::vector<std::tuple<eosio::name, eosio::name>> aacts;
    std::vector<std::tuple<eosio::name, std::string>> ac;

    std::vector<kyc_prov> kyc;

    uint64_t primary_key() const { return acc.value; }
};
typedef eosio::multi_index<"usersinfo"_n, userinfo> usersinfo;







