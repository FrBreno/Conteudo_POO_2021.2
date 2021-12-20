#include "../Account/Account.hpp"
#include <vector>

class Client
{
  std::vector<std::shared_ptr<Account>> accounts;
  std::string clientid{};

public:
  Client(std::string clientid);
  void addAccount(std::shared_ptr<Account> account);
  friend std::ostream &operator<<(std::ostream &os, const Client &c);

  std::vector<std::shared_ptr<Account>> getAccounts() const;
  std::string getClientid() const;
  void setAccounts(std::vector<std::shared_ptr<Account>> accounts);
  void setClientid(std::string clientid);
};