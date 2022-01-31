#include "user.hpp"

User::User(const std::string &userName) : userName{userName} {}

void User::follow(User *other)
{
  auto key = other->userName;
  if (this->userName == key)
  {
    throw std::runtime_error("Voce nao pode seguir a si mesmo.");
  }
  if (this->following.find(key) != this->following.end())
  {
    throw std::runtime_error("Voce ja segue esse usuario.");
  }
  this->following[key] = other;
  other->followers[this->userName] = this;
}

void User::unfollow(std::string userName)
{
  auto it = this->following.find(userName);
  if (it == this->following.end())
  {
    throw std::runtime_error("Voce nao segue esse usuario.");
  }
  User *other = it->second;
  this->following.erase(it);

  auto it_other = other->followers.find(this->userName);
  other->followers.erase(it_other);

  this->inbox.rmMsgsFrom(userName);
}

void User::like(int twid)
{
  this->inbox.getTweet(twid)->like(this->userName);
}

void User::sendTweet(Tweet *tw)
{
  this->inbox.storeInMyTweets(tw);
  for (auto &seguidores : this->followers)
  {
    seguidores.second->inbox.storeInTimeline(tw);
  }
}

Inbox &User::getInbox()
{
  return this->inbox;
}

void User::unfollowAll()
{
  while ((int)this->following.size() > 0)
  {
    unfollow(this->following.begin()->second->userName);
  }
}

void User::rejectAll()
{
  while ((int)this->followers.size() > 0)
  {
    auto it = this->followers.begin();
    it->second->unfollow(this->userName);
  }
}

std::ostream &operator<<(std::ostream &os, const User &user)
{
  int followingSize = (int)user.following.size();
  int followersSize = (int)user.followers.size();

  os << user.userName << "\n";
  os << "\tseguidos   [";

  for (auto sigo : user.following)
  {
    os << sigo.second->userName;
    if (followingSize > 1)
    {
      os << ", ";
    }
    followingSize--;
  }

  os << "]\n\tseguidores [";
  for (auto seguidores : user.followers)
  {
    os << seguidores.second->userName;
    if (followersSize > 1)
    {
      os << ", ";
    }
    followersSize--;
  }
  os << "]";

  return os;
}