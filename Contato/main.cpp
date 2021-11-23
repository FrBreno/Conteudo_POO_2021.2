#include "Contact/contact.hpp"
#include <sstream>

int main()
{
  Contact contact("");

  while (true)
  {
    cout << "$ ";
    string line{};
    getline(cin, line);
    stringstream ss(line);

    string cmd{};
    ss >> cmd;

    if (cmd == "show")
    {
      cout << contact.toString() << endl;
    }
    else if (cmd == "init")
    {
      string name{};
      ss >> name;

      contact.setName(name);
    }
    else if (cmd == "add")
    {
      string id{};
      string number{};
      ss >> id >> number;

      contact.addFone(Fone(id, number));
    }
    else if (cmd == "rm")
    {
      int index{0};
      ss >> index;
      contact.rmFone(index);
    }
    else if (cmd == "end")
    {
      break;
    }
    else
    {
      cout << "Comando Invalido\n";
    }
  }

  return 0;
}