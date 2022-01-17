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
  Message();
  Message(int id, std::string userName, std::string msg);
  void like(std::string userName);

  int getId() const;
  friend std::ostream &operator<<(std::ostream &os, const Message &mes);
};