#include <sstream>
#include "Auxiliares/auxiliar.hpp"
#include "Controller/controller.hpp"

void helpCommands()
{
  std::cout << "\n\nMenu de ajuda:\n";
  std::cout << "$ add <string>\n";
  std::cout << "$ follow <string> <string>\n";
  std::cout << "$ unfollow <string> <string>\n";
  std::cout << "$ twittar <string> <string>\n";
  std::cout << "$ timeline <string>\n";
  std::cout << "$ like <string> <int>\n";
  std::cout << "$ rt <string> <int> <string>\n";
  std::cout << "$ rm <string>\n";
  std::cout << "$ show\n";
  std::cout << "$ end\n\n";
  return;
}

int main()
{
  Controller controller;
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
      if (cmd == "add")
      {
        controller.addUser(read<std::string>(ss));
      }
      else if (cmd == "show")
      {
        std::cout << controller << std::endl;
      }
      else if (cmd == "follow")
      {
        controller.getUser(read<std::string>(ss))->follow(controller.getUser(read<std::string>(ss)));
      }
      else if (cmd == "twittar")
      {
        std::string username = read<std::string>(ss);
        std::string msg = read_str<std::string>(ss);
        controller.sendTweet(username, msg);
      }
      else if (cmd == "rt")
      {
        std::string username = read<std::string>(ss);
        int id = read<int>(ss);
        std::string msg = read_str<std::string>(ss);
        controller.sendRt(username, id, msg);
      }
      else if (cmd == "rm")
      {
        controller.rmUser(read<std::string>(ss));
      }
      else if (cmd == "timeline")
      {
        User *user = controller.getUser(read<std::string>(ss));
        std::cout << user->getInbox() << std::endl;
      }
      else if (cmd == "like")
      {
        controller.getUser(read<std::string>(ss))->like(read<int>(ss));
      }
      else if (cmd == "unfollow")
      {
        controller.getUser(read<std::string>(ss))->unfollow(read<std::string>(ss));
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