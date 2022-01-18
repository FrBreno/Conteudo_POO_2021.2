#include "user.hpp"

User::User(const std::string &userName) : userName{userName} {}

void User::follow(User *other)
{
  auto key = other->userName;
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
}

void User::like(int twid)
{
  this->inbox.getTweet(twid)->like(this->userName);
}

void User::sendTweet(Message *tw)
{
  this->inbox.store(tw);
  for (auto &seguidores : this->followers)
  {
    seguidores.second->inbox.receiveNew(tw);
  }
}

Inbox &User::getInbox()
{
  return this->inbox;
}

std::ostream &operator<<(std::ostream &os, const User &user)
{
  os << user.userName << "\n";
  os << "\tseguidos   [ ";

  for (auto sigo : user.following)
  {
    os << sigo.second->userName;
    if ((int)user.following.size() > 1)
    {
      os << ",";
    }
    os << " ";
  }

  os << "]\n\tseguidores [ ";
  for (auto seguidores : user.followers)
  {
    os << seguidores.second->userName;
    if ((int)user.followers.size() > 1)
    {
      os << ",";
    }
    os << " ";
  }
  os << "]";

  return os;
}