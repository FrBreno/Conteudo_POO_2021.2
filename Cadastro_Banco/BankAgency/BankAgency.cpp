#include "BankAgency.hpp"

BankAgency::BankAgency() {}

void BankAgency::addClient(std::string clientid)
{
  // Tenta adicionar o cliente:
  auto [it, res] = this->clients.insert(std::make_pair(clientid, std::make_shared<Client>(clientid)));
  // Exceção:
  if (res == false)
  {
    throw std::runtime_error("Cliente ja existe!");
  }

  // Criando CC/CP e inserindo no vetor de contas do cliente:
  this->nextAccount++;
  (*it).second->addAccount(std::make_shared<CheckingAccount>(this->nextAccount, clientid));
  this->nextAccount++;
  (*it).second->addAccount(std::make_shared<SavingsAccount>(this->nextAccount, clientid));

  // Inserindo as contas do cliente no mao de contas:
  for (auto contas : (*it).second->getAccounts())
  {
    auto [it2, res2] = this->accounts.insert(std::make_pair(contas->getId(), contas));
    (void)it2;
    if (res2 == false)
    {
      throw std::runtime_error("Erro ao adicionar conta na agencia.");
    }
  }
}

void BankAgency::deposit(int idConta, float value)
{
  if (value < 0)
  {
    throw std::runtime_error("Nao se pode depositar valores negativos.");
  }
  std::shared_ptr<Account> conta = this->getAccount(idConta);
  conta->deposit(value);
}

void BankAgency::monthlyUpdate()
{
  if (this->accounts.size() == 0)
  {
    throw std::runtime_error("Sem contas cadastradas!");
  }
  for (auto &contas : this->accounts)
  {
    contas.second->monthlyUpdate();
  }
}

void BankAgency::transfer(int contaDe, int contaPara, float value)
{
  if (value < 0)
  {
    throw std::runtime_error("Valor invalido para transferencia");
  }
  std::shared_ptr<Account> conta01 = this->getAccount(contaDe);
  if (conta01->getBalance() < value)
  {
    throw std::runtime_error("saldo insuficiente");
  }

  std::shared_ptr<Account> conta02 = this->getAccount(contaPara);
  conta01->transfer(conta02, value);
}

void BankAgency::withdraw(int idConta, float value)
{
  std::shared_ptr<Account> conta = this->getAccount(idConta);
  if (value < 0)
  {
    throw std::runtime_error("Valor invalido para saque.");
  }
  if (conta->getBalance() < value)
  {
    throw std::runtime_error("Valor do saque excede o saldo!");
  }

  conta->withdraw(value);
}

std::ostream &operator<<(std::ostream &os, const BankAgency &bk)
{
  os << "Clients:\n";
  for (auto &cli : bk.clients)
  {
    os << *cli.second << std::endl;
  }
  os << "Accounts:\n";
  for (auto &contas : bk.accounts)
  {
    os << *contas.second << std::endl;
  }
  return os;
}