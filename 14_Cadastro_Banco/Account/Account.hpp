#include <iostream>
#include <memory>

class Account
{
protected:
  float balance{0};
  std::string clientid{};
  int id{0};
  std::string type{};

public:
  Account(int id, std::string clientid);
  void deposit(float value);
  virtual void monthlyUpdate() = 0; // atualizacao mensal
  void transfer(std::shared_ptr<Account> other, float value);
  void withdraw(float value); // saque
  friend std::ostream &operator<<(std::ostream &os, const Account &ac);

  float getBalance() const;
  std::string getClientid() const;
  int getId() const;
  std::string getType() const;

  virtual ~Account();
};

// CONTA CORRENTE:
class CheckingAccount : public Account
{
public:
  CheckingAccount(int id, std::string idClient);
  void monthlyUpdate() override;
};

// CONTA POUPANCA:
class SavingsAccount : public Account
{
public:
  SavingsAccount(int id, std::string idClient);
  void monthlyUpdate() override;
};