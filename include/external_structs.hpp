
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

struct[[ eosio::table("participants"), eosio::contract("freeosgov") ]] participant {
  std::string account_type;            // user's verification level
  uint32_t registered_iteration;  // when the user was registered
  uint32_t issuances;             // total number of times the user has been issued with POINTs
  eosio::asset total_issuance_amount;    // accrued POINTs
  uint32_t last_claim;            // the last iteration in which the user attempted to claim
  uint32_t surveys;               // how many surveys the user has completed
  uint32_t votes;                 // how many votes the user has completed
  uint32_t ratifys;               // how many ratifys the user has completed  

  uint64_t primary_key() const { return 0; } // return a constant to ensure a single-row table
};
using participants_index = eosio::multi_index<"participants"_n, participant>;







