#include "../Client/Client.hpp"
#include <map>
#include <stdexcept>

class BankAgency
{
  std::map<int, std::shared_ptr<Account>> accounts;
  std::map<std::string, std::shared_ptr<Client>> clients;
  int nextAccount{-1};

  std::shared_ptr<Account> getAccount(int id)
  {
    if (accounts.find(id) != accounts.end())
    {
      return (accounts.find(id)->second);
    }
    throw std::runtime_error("Conta nao encontrada!");
  }

public:
  BankAgency();
  void addClient(std::string clientid);
  void deposit(int idConta, float value);
  void monthlyUpdate();
  void transfer(int contaDe, int contaPara, float value);
  void withdraw(int idConta, float value); // saque
  friend std::ostream &operator<<(std::ostream &os, const BankAgency &bk);
};