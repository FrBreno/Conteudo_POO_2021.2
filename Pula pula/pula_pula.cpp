#include "trampoline/trampoline.hpp"
#include <sstream>

int main()
{
     Trampoline trampo(0, 0, 0);
     while (true)
     {
          cout << "$ ";

          string line;
          getline(cin, line);
          stringstream ss(line);

          string cmd;
          ss >> cmd;

          if (cmd == "exit")
          {
               trampo.exit();
               break;
          }
          else if (cmd == "init")
          {
               int max{0};
               int idade_max{0};
               int idade_min{0};

               ss >> max >> idade_max >> idade_min;
               trampo.setParametros(max, idade_max, idade_min);
          }
          else if (cmd == "arrive")
          {
               string name;
               int age;
               ss >> name >> age;

               auto p = make_shared<Kid>(name, age);
               trampo.arrive(p);
          }
          else if (cmd == "show")
          {
               cout << trampo.toString() << endl;
          }
          else if (cmd == "in")
          {
               trampo.in();
          }
          else if (cmd == "out")
          {
               trampo.out();
          }
          else if (cmd == "remove")
          {
               string name;
               int age;
               ss >> name >> age;

               trampo.remove(name, age);
          }
          else
          {
               cout << "Comando incorreto\n";
          }
     }

     return 0;
}