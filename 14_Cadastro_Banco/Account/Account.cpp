#include "Account.hpp"

Account::Account(int id, std::string clientid)
{
  this->id = id;
  this->clientid = clientid;
}

void Account::deposit(float value)
{
  this->balance += value;
}

void Account::monthlyUpdate() {}

void Account::transfer(std::shared_ptr<Account> other, float value)
{
  this->balance -= value;
  other->balance += value;
}

void Account::withdraw(float value)
{
  this->balance -= value;
}
std::ostream &operator<<(std::ostream &os, const Account &ac)
{
  os << ac.id << ":" << ac.clientid << ":" << ac.balance << ":" << ac.type;
  return os;
}

float Account::getBalance() const
{
  return this->balance;
}

std::string Account::getClientid() const
{
  return this->clientid;
}

int Account::getId() const
{
  return this->id;
}

std::string Account::getType() const
{
  return this->type;
}

Account::~Account() {}

// CONTA CORRENTE:
CheckingAccount::CheckingAccount(int id, std::string idClient) : Account(id, idClient)
{
  this->type = "CC";
}

void CheckingAccount::monthlyUpdate()
{
  this->balance -= 20;
}

// CONTA POUPANCA:
SavingsAccount::SavingsAccount(int id, std::string idClient) : Account(id, idClient)
{
  this->type = "CP";
}

void SavingsAccount::monthlyUpdate()
{
  this->balance += (this->balance / 100.0);
}