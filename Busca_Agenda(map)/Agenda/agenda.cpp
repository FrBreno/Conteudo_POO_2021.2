#include "agenda.hpp"

Agenda::Agenda() {}

void Agenda::addContact(Contact contact)
{
  map<string, Contact>::iterator it = this->contacts.find(contact.getName());
  if (it != this->contacts.end())
  {
    for (Fone fone : contact.getFones())
    {
      it->second.addFone(fone);
    }
    cout << "O contato " << contact.getName() << " foi atualizado!\n";
    return;
  }
  this->contacts[contact.getName()] = contact;
  return;
}

Contact *Agenda::getContact(string name)
{
  map<string, Contact>::iterator it = this->contacts.find(name);
  if (it != this->contacts.end())
  {
    return &(*it).second;
  }
  return nullptr;
}

void Agenda::rmContact(string name)
{
  map<string, Contact>::iterator it = this->contacts.find(name);
  if (it != this->contacts.end())
  {
    this->contacts.erase(it);
    return;
  }
  cout << "[ERROR!] Contato inexistente!\n";
  return;
}

vector<Contact> Agenda::search(string pattern)
{
  vector<Contact> aux;
  for (auto &[nome, contato] : this->contacts)
  {
    stringstream ss;
    ss << contato;
    string text_contac = ss.str();

    if (text_contac.find(pattern) != string::npos)
    {
      aux.push_back(contato);
    }
  }
  return aux;
}

vector<Contact> Agenda::getContacts()
{
  vector<Contact> res;
  for (auto &[nome, contato] : this->contacts)
  {
    res.push_back(contato);
  }
  return res;
}

void Agenda::exit()
{
  this->contacts.clear();
  return;
}