#include "../Contact/contact.hpp"
#include <algorithm>
#include <sstream>

class Agenda
{
  vector<Contact> contacts;
  int findPos(string name);

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
    for (Contact contato : a.contacts)
    {
      os << contato << endl;
    }
    return os;
  }
};