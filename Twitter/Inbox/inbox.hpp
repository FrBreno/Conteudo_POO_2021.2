#include "../Message/message.hpp"
#include <map>
#include <vector>
#include <memory>

class Inbox
{
private:
  std::map<int, Message> allMsgs;
  std::map<int, Message> unread;

public:
  Inbox();
  void receiveNew(Message tweet);
  void store(Message tweet);

  std::vector<Message> getAll();
  Message *getTweet(int id);
  std::vector<Message> getUnread();
  friend std::ostream &operator<<(std::ostream &os, const Inbox &in);
};