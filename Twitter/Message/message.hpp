#include <iostream>
#include <set>

class Message
{
private:
  int id;
  std::set<std::string> likes;
  std::string userName;
  std::string msg;

public:
  Message(int id, const std::string &userName, const std::string &msg);
  void like(const std::string &username);

  int getId() const;
  friend std::ostream &operator<<(std::ostream &os, const Message &mes);
};