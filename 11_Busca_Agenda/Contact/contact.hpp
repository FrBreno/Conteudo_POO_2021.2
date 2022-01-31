#include "../Fone/fone.hpp"
#include <vector>

class Contact
{
  vector<Fone> fones;
  string name{};

public:
  Contact(string name);
  void addFone(Fone fone);
  void rmFone(int index);
  // string toString();

  void setName(string name);
  string getName();
  vector<Fone> getFones();

  friend std::ostream &operator<<(std::ostream &os, Contact &a)
  {
    os << "- " + a.name;
    for (int i{0}; i < (int)a.fones.size(); i++)
    {
      os << " [" << to_string(i) << ":" << a.fones[i].toString() << "]";
    }
    return os;
  }
};