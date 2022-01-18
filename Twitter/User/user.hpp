#include "../Inbox/inbox.hpp"

class User
{
private:
  // Meus seguidores:
  std::map<std::string, User *> followers;
  // Aqueles que eu sigo:
  std::map<std::string, User *> following;
  Inbox inbox;
  std::string userName;

public:
  User(const std::string &userName);
  void sendTweet(Message *tw);
  void follow(User *other);
  void unfollow(std::string userName);
  void like(int twid);
  Inbox &getInbox();

  friend std::ostream &operator<<(std::ostream &os, const User &user);
};