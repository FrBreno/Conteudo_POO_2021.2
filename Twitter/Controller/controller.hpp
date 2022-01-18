#include "../User/user.hpp"
#include <memory>

class Controller
{
private:
  int nextTwid{0};
  std::map<int, std::shared_ptr<Message>> tweets;
  std::map<std::string, std::shared_ptr<User>> users;

  Message *createMsg(std::string username, std::string msg);

public:
  Controller();
  void addUser(std::string username);
  User *getUser(std::string username);
  void sendTweet(std::string username, std::string msg);

  friend std::ostream &operator<<(std::ostream &os, const Controller &control);
};