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
  void follow(User *other);
  Inbox &getInbox();
  void sendTweet(Tweet *tw);
  void unfollow(std::string userName);
  void like(int twid);
  void unfollowAll();
  void rejectAll();

  friend std::ostream &operator<<(std::ostream &os, const User &user);
};