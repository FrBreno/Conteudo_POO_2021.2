#include "inbox.hpp"

Inbox::Inbox() {}

void Inbox::receiveNew(Message tweet)
{
  this->unread[tweet.getId()] = tweet;
  this->store(tweet);
}

void Inbox::store(Message tweet)
{
  this->allMsgs[tweet.getId()] = tweet;
}

std::vector<Message> Inbox::getAll()
{
  std::vector<Message> result;
  for (auto &msg : this->allMsgs)
  {
    result.push_back(msg.second);
  }
  return result;
}

Message *Inbox::getTweet(int id)
{
  auto it = this->allMsgs.find(id);
  if (it == this->allMsgs.end())
  {
    throw std::runtime_error("Tweet nao encontrado!");
  }
  return &it->second;
}

std::vector<Message> Inbox::getUnread()
{
  std::vector<Message> result;

  for (auto &msg : this->unread)
  {
    result.push_back(msg.second);
  }
  this->unread.clear();
  return result;
}

std::ostream &operator<<(std::ostream &os, const Inbox &in)
{
  for (auto msg : in.allMsgs)
  {
    os << msg.second << "\n";
  }
  return os;
}