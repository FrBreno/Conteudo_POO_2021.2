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
  string toString();

  void setName(string name);
  string getName();
  vector<Fone> getFones();
};