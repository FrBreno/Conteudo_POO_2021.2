#include "adm/adm.hpp"
#include <sstream>

int main()
{
  Adm adm;

  while (true)
  {
    cout << "$ ";

    string line;
    getline(cin, line);
    stringstream ss(line);

    string cmd;
    ss >> cmd;

    if (cmd == "end")
    {
      adm.exitAdm();
      break;
    }
    else if (cmd == "init")
    {
      int capacidade{0};
      ss >> capacidade;
      adm.criarSala(capacidade);
    }
    else if (cmd == "show")
    {
      cout << adm.toString() << endl;
    }
    else if (cmd == "reservar")
    {
      string id{};
      string fone{};
      int ind{0};

      ss >> id >> fone >> ind;
      adm.reservar(id, fone, ind);
    }
    else if (cmd == "cancelar")
    {
      string id{};

      ss >> id;
      adm.cancelar(id);
    }
    else
    {
      cout << "\nComando invalido!\n\n";
    }
  }

  return 0;
}