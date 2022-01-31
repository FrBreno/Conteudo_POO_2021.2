#include "../User/user.hpp"
#include <memory>

class Controller
{
private:
  int nextTwid{0};
  std::map<int, std::shared_ptr<Tweet>> tweets;
  std::map<std::string, std::shared_ptr<User>> users;

  Tweet *createMsg(std::string username, std::string msg);

public:
  Controller();
  void addUser(std::string username);
  User *getUser(std::string username);
  void sendTweet(std::string username, std::string msg);
  void sendRt(std::string username, int twId, std::string msg);
  void rmUser(std::string username);

  friend std::ostream &operator<<(std::ostream &os, const Controller &control);
};