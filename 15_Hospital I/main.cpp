#include <sstream>
#include "Hospital/hospital.hpp"

void helpCommands()
{
  std::cout << "\n\nMenu de ajuda:\n";
  std::cout << "$ addPacs <string> <string> ... <string>\n";
  std::cout << "$ addMeds <string> <string> ... <string>\n";
  std::cout << "$ tie <string>_med <string>_pac <string>_pac ... <string>_pac\n";
  std::cout << "$ show\n";
  std::cout << "$ end\n\n";
  return;
}

void divide_str(std::string &s, char delim)
{
  for (int i{0}; i < (int)s.length(); i++)
  {
    if (s[i] == delim)
    {
      s[i] = ' ';
    }
  }
  return;
}

int main()
{
  Hospital hospital;
  std::cout << "\nDigite 'help' para acessar a lista de comandos.\n\n";
  while (true)
  {
    std::cout << "$ ";

    std::string line{};
    std::getline(std::cin, line);
    std::stringstream ss(line);

    std::string cmd{};
    ss >> cmd;

    try
    {
      if (cmd == "addPacs")
      {
        std::string line2{};
        std::string sender, diag;
        while (ss >> line2)
        {
          divide_str(line2, '-');
          std::stringstream s2(line2);
          s2 >> sender >> diag;
          Paciente p(sender, diag);
          hospital.addPaciente(std::make_shared<Paciente>(p));
        }
      }
      else if (cmd == "addMeds")
      {
        std::string line2{};
        std::string sender, classe;
        while (ss >> line2)
        {
          divide_str(line2, '-');
          std::stringstream s2(line2);
          s2 >> sender >> classe;
          Medico m(sender, classe);
          hospital.addMedico(std::make_shared<Medico>(m));
        }
      }
      else if (cmd == "show")
      {
        std::cout << "\n";
        std::cout << hospital << "\n\n";
      }
      else if (cmd == "tie")
      {
        std::string nomeMedico;
        ss >> nomeMedico;
        std::string nomePac{};
        while (ss >> nomePac)
        {
          hospital.vincular(nomeMedico, nomePac);
        }
      }
      else if (cmd == "end")
      {
        break;
      }
      else if (cmd == "help")
      {
        helpCommands();
      }
      else
      {
        std::cout << "\n[ERROR!] Comando invalido!\n";
      }
    }
    catch (const std::runtime_error &e)
    {
      std::cout << "Fail!: " << e.what() << '\n';
    }
  }

  return 0;
}