#include "../User/user.hpp"

class Controller
{
private:
  int nextTwid{0};
  std::map<int, Message> tweets;
  std::map<std::string, User> users;

public:
  Controller();
  void addUser(std::string username);
  User *getUser(std::string username);
  void sendTweet(std::string username, std::string msg);

  friend std::ostream &operator<<(std::ostream &os, const Controller &control);
};