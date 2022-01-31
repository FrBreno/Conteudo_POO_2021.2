#include "controller.hpp"

Tweet *Controller::createMsg(std::string username, std::string msg)
{
  Tweet *message = new Tweet(this->nextTwid, username, msg);
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
  auto it = this->tweets[this->nextTwid] = std::make_shared<Tweet>(*createMsg(username, msg));
  user->sendTweet(&(*it));
}

void Controller::sendRt(std::string username, int twId, std::string msg)
{
  User *user = getUser(username);

  sendTweet(username, msg);
  Tweet *tweetRt = user->getInbox().getTweet(this->nextTwid - 1);
  Tweet *tweet = user->getInbox().getTweet(twId);
  tweetRt->setRt(tweet);
}

void Controller::rmUser(std::string username)
{
  User *user = getUser(username);
  user->unfollowAll();
  user->rejectAll();
  auto tweets = user->getInbox().getMyTweets();
  for (auto tweet : tweets)
  {
    tweet->setDeleted();
  }
  this->users.erase(users.find(username));
}

std::ostream &operator<<(std::ostream &os, const Controller &control)
{
  for (auto user : control.users)
  {
    os << *user.second << "\n";
  }
  return os;
}
