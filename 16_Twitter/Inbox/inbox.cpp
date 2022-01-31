#include "inbox.hpp"

Inbox::Inbox() {}

void Inbox::storeInTimeline(Tweet *tweet)
{
  this->timeline[tweet->getId()] = tweet;
}

void Inbox::storeInMyTweets(Tweet *tweet)
{
  this->myTweets[tweet->getId()] = tweet;
  this->storeInTimeline(tweet);
}

std::vector<Tweet *> Inbox::getTimeline() const
{
  std::vector<Tweet *> result;
  for (auto &msg : this->timeline)
  {
    if (!msg.second->isDeleted())
    {
      result.push_back(msg.second);
    }
  }
  return result;
}

std::vector<Tweet *> Inbox::getMyTweets() const
{
  std::vector<Tweet *> result;

  for (auto &msg : this->myTweets)
  {
    result.push_back(msg.second);
  }
  return result;
}

Tweet *Inbox::getTweet(int id)
{
  auto it = this->timeline.find(id);
  if (it == this->timeline.end())
  {
    throw std::runtime_error("Tweet nao encontrado!");
  }
  return it->second;
}

void Inbox::rmMsgsFrom(const std::string &username)
{
  std::vector<int> ids;
  for (auto &tLine : this->timeline)
  {
    std::string name = tLine.second->getSender();
    if (name == username)
    {

      ids.push_back(tLine.second->getId());
    }
  }
  for (int id : ids)
  {
    auto it = this->timeline.find(id);
    this->timeline.erase(it);
  }
}

std::ostream &operator<<(std::ostream &os, Inbox &in)
{
  std::vector<Tweet *> tLine = in.getTimeline();
  int size = (int)tLine.size();
  while (size > 0)
  {
    os << *tLine[size - 1] << "\n";
    tLine.pop_back();
    size--;
  }
  return os;
}