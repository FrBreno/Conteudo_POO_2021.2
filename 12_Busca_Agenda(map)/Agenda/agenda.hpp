#include "../Contact/contact.hpp"
#include <sstream>
#include <map>

class Agenda
{
  map<string, Contact> contacts{};

public:
  Agenda();
  void addContact(Contact contact);
  Contact *getContact(string name);
  void rmContact(string name);

  vector<Contact> search(string pattern);
  vector<Contact> getContacts();
  void exit();

  friend std::ostream &operator<<(std::ostream &os, const Agenda &a)
  {
    if ((int)a.contacts.size() == 0)
    {
      os << "Sem contatos na agenda\n";
      return os;
    }
    for (auto [nome, contato] : a.contacts)
    {
      os << contato << endl;
    }
    return os;
  }
};