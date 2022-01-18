#include "controller.hpp"

Message *Controller::createMsg(std::string username, std::string msg)
{
  Message *message = new Message(this->nextTwid, username, msg);
  this->nextTwid++;
  return message;
}

Controller::Controller()
{
}

void Controller::addUser(std::string username)
{
  auto [it, test] = this->users.insert(std::make_pair(username, std::make_shared<User>(username)));

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
  return &(*it->second);
}

void Controller::sendTweet(std::string username, std::string msg)
{
  User *user = getUser(username);
  auto it = this->tweets[this->nextTwid] = std::make_shared<Message>(*createMsg(username, msg));
  user->sendTweet(&(*it));
}

std::ostream &operator<<(std::ostream &os, const Controller &control)
{
  for (auto user : control.users)
  {
    os << *user.second << "\n";
  }
  return os;
}
