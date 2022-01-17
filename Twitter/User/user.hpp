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
  User();
  User(std::string id);
  void follow(User *other);
  void unfollow(std::string userName);
  void like(int twid);
  void sendTweet(Message tw);

  void addFollower(User *other);
  void rmFollower(std::string userName);
  void addInbox(Message tw);

  std::string getUsername();
  Inbox getInbox();
  friend std::ostream &operator<<(std::ostream &os, const User &user);
};