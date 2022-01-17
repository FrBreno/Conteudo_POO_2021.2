#include "controller.hpp"

Controller::Controller() {}

void Controller::addUser(std::string username)
{
  auto [it, test] = this->users.insert(std::make_pair(username, User(username)));

  if (!test)
  {
    throw std::runtime_error("O Usuario ja existe");
  }
}

User *Controller::getUser(std::string username)
{
  auto it = this->users.find(username);
  if (it == this->users.end())
  {
    throw std::runtime_error("Usuario nao encontrado.");
  }
  return &it->second;
}

void Controller::sendTweet(std::string username, std::string msg)
{
  User *user = getUser(username);
  Message(this->nextTwid, username, msg);
  auto it = this->tweets[this->nextTwid] = Message(this->nextTwid, username, msg);

  this->nextTwid++;
  user->sendTweet(it);
}

std::ostream &operator<<(std::ostream &os, const Controller &control)
{
  for (auto user : control.users)
  {
    os << user.second << "\n";
  }
  return os;
}
