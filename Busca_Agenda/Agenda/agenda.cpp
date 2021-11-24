#include "agenda.hpp"

int Agenda::findPos(string name)
{
  for (int i{0}; i < (int)this->contacts.size(); i++)
  {
    if (this->contacts[i].getName() == name)
    {
      return i;
    }
  }
  return -1;
}

Agenda::Agenda() {}

void Agenda::addContact(Contact contact)
{
  int indice = findPos(contact.getName());
  if (indice != -1) //Caso exista um contato de mesmo nome.
  {
    vector<Fone> fones = contact.getFones();
    for (auto &f : fones)
    {
      this->contacts[indice].addFone(f);
    }
    return;
  }
  this->contacts.push_back(contact);

  sort(this->contacts.begin(), this->contacts.end(), [](Contact c1, Contact c2)
       { return c1.getName() < c2.getName(); });
  return;
}

Contact *Agenda::getContact(string name)
{
  int indice = findPos(name);
  if (indice != -1)
  {
    return &contacts[indice];
  }
  return nullptr;
}

void Agenda::rmContact(string name)
{
  int indice = findPos(name);
  if (indice != -1)
  {
    this->contacts.erase(this->contacts.begin() + indice);
    return;
  }
  cout << "[ERROR!] Contato nao encontrado.\n";
  return;
}

vector<Contact> Agenda::search(string pattern)
{
  vector<Contact> result;
  for (auto &c : this->contacts)
  {
    stringstream ss;
    ss << c;
    string text_contact = ss.str();

    if (text_contact.find(pattern) != string::npos)
    {
      result.push_back(c);
    }
  }
  return result;
}

vector<Contact> Agenda::getContacts()
{
  return this->contacts;
}

void Agenda::exit()
{
  this->contacts.clear();
  return;
}