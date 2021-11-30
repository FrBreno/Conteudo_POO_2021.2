#include "Agenda/agenda.hpp"

void show_help()
{
  cout << "\nadd <string> <string>:<string>\n";
  cout << "show\n";
  cout << "rmFone <string> <int>\n";
  cout << "rm <string>\n";
  cout << "search <string>\n";
  cout << "end\n\n";
  return;
}

int main()
{
  Agenda agenda;
  cout << "\nDigite 'help' para acessar a lista de comandos.\n\n";

  while (true)
  {
    cout << "$ ";

    string line{};
    getline(cin, line);
    stringstream ss(line);

    string cmd{};
    ss >> cmd;

    if (cmd == "add")
    {
      string name, id, number, aux;
      ss >> name;

      Contact contato(name);
      while (ss >> aux)
      {
        for (int i{0}; i < (int)aux.length(); i++)
        {
          if (aux[i] == ':')
          {
            aux[i] = ' ';
          }
        }
        stringstream s2(aux);
        s2 >> id >> number;
        contato.addFone(Fone(id, number));
      }
      agenda.addContact(contato);
    }
    else if (cmd == "show")
    {
      cout << agenda << endl;
    }
    else if (cmd == "rmFone")
    {
      string name{};
      int indice{};
      ss >> name >> indice;

      Contact *contato = agenda.getContact(name);
      if (contato != nullptr)
      {
        contato->rmFone(indice);
      }
      else
      {
        cout << "[ERROR!] Contato nao encontrado.\n";
      }
    }
    else if (cmd == "rm")
    {
      string name{};
      ss >> name;
      agenda.rmContact(name);
    }
    else if (cmd == "search")
    {
      string pattern{};
      ss >> pattern;

      vector<Contact> busca = agenda.search(pattern);
      if ((int)busca.size() == 0)
      {
        cout << "Nada foi encontrado :/\n";
      }
      else
      {
        for (auto &c : busca)
        {
          cout << c << endl;
        }
        cout << endl;
      }
    }
    else if (cmd == "end")
    {
      agenda.exit();
      break;
    }
    else if (cmd == "help")
    {
      show_help();
    }
    else
    {
      cout << "[ERROR!] Comando invalido.\n";
    }
  }

  return 0;
}