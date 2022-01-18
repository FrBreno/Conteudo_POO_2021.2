#include "../Message/message.hpp"
#include <map>
#include <vector>
#include <memory>

class Inbox
{
private:
  std::map<int, Message *> allMsgs;
  std::map<int, Message *> unread;

public:
  Inbox();
  std::vector<Message *> getUnread();
  std::vector<Message *> getAll() const;
  Message *getTweet(int id);

  void receiveNew(Message *tweet);
  void store(Message *tweet);

  friend std::ostream &operator<<(std::ostream &os, Inbox &in);
};