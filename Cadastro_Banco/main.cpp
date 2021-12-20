#include "BankAgency/BankAgency.hpp"
#include <sstream>
#include <iomanip>

void helpCommands()
{
  std::cout << "\n\nMenu de ajuda:\n";
  std::cout << "$ addCli <string>\n";
  std::cout << "$ deposito <int> <float>\n";
  std::cout << "$ saque <int> <float>\n";
  std::cout << "$ transf <int> <int> <float>\n";
  std::cout << "$ update\n";
  std::cout << "$ show\n";
  std::cout << "$ end\n\n";
  return;
}

int main()
{
  std::cout << std::fixed << std::setprecision(2); // Fixando n° de algarismos apos o ponto flutuante.

  BankAgency bradesco;

  while (true)
  {
    std::cout << "$ ";
    std::string line{};
    getline(std::cin, line);
    std::stringstream ss{line};

    std::string cmd{};
    ss >> cmd;

    try
    {
      if (cmd == "end")
      {
        break;
      }
      else if (cmd == "show")
      {
        std::cout << bradesco << std::endl;
      }
      else if (cmd == "addCli")
      {
        std::string cliente{};
        ss >> cliente;

        bradesco.addClient(cliente);
      }
      else if (cmd == "deposito")
      {
        int id{0};
        float value{0};

        ss >> id >> value;
        bradesco.deposit(id, value);
      }
      else if (cmd == "saque")
      {
        int id{0};
        float value{0};

        ss >> id >> value;
        bradesco.withdraw(id, value);
      }
      else if (cmd == "transf")
      {
        int de{0};
        int para{0};
        float value{0};

        ss >> de >> para >> value;
        bradesco.transfer(de, para, value);
      }
      else if (cmd == "update")
      {
        bradesco.monthlyUpdate();
      }
      else if (cmd == "help")
      {
        helpCommands();
      }
      else
      {
        std::cout << "Comando invalido! ('$ help' para ajuda)\n";
      }
    }
    catch (std::runtime_error &e)
    {
      std::cout << "fail: " << e.what() << std::endl;
    }
  }
  return 0;
}