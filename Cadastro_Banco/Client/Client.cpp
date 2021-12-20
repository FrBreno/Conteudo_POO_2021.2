#include "Client.hpp"

Client::Client(std::string clientid) : clientid{clientid} {}

void Client::addAccount(std::shared_ptr<Account> account)
{
  this->accounts.push_back(std::shared_ptr<Account>(account));
}

std::ostream &operator<<(std::ostream &os, const Client &c)
{
  int cont{0};
  os << "- " << c.clientid << " [";
  for (auto conta : c.accounts)
  {
    if (cont == 0)
    {
      os << (*conta).getId() << ", ";
    }
    else
    {
      os << (*conta).getId() << "]";
    }
    cont++;
  }
  return os;
}

std::vector<std::shared_ptr<Account>> Client::getAccounts() const
{
  return this->accounts;
}

std::string Client::getClientid() const
{
  return this->clientid;
}

void Client::setAccounts(std::vector<std::shared_ptr<Account>> accounts)
{
  this->accounts = accounts;
}

void Client::setClientid(std::string clientid)
{
  this->clientid = clientid;
}