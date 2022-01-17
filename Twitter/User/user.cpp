#include "user.hpp"

User::User() {}

User::User(std::string id) : userName{id} {}

void User::follow(User *other)
{
  auto key = other->getUsername();
  if (this->following.find(key) != this->following.end())
  {
    throw std::runtime_error("Voce ja segue esse usuario.");
  }
  this->following[key] = other;
  other->addFollower(this);
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
  other->rmFollower(this->userName);
}

void User::like(int twid)
{
  this->inbox.getTweet(twid)->like(this->userName);
}

void User::sendTweet(Message tw)
{
  this->inbox.store(tw);
  for (auto &seguidores : this->followers)
  {
    seguidores.second->addInbox(tw);
  }
}

void User::addFollower(User *other)
{
  this->followers[other->getUsername()] = other;
}

void User::rmFollower(std::string userName)
{
  auto it = this->followers.find(userName);
  this->followers.erase(it);
}

void User::addInbox(Message tw)
{
  this->inbox.receiveNew(tw);
}

std::string User::getUsername()
{
  return this->userName;
}

Inbox User::getInbox()
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