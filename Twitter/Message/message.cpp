#include "message.hpp"

Message::Message(int id, const std::string &userName, const std::string &msg) : id{id}, userName{userName}, msg{msg} {}

void Message::like(const std::string &username)
{
  this->likes.insert(username);
}

int Message::getId() const
{
  return this->id;
}

std::ostream &operator<<(std::ostream &os, const Message &mes)
{
  int size = (int)mes.likes.size();

  os << mes.id << ":" << mes.userName;
  os << " (" << mes.msg << ") [";
  for (auto like : mes.likes)
  {
    os << " " << like;
    if (size > 1)
    {
      os << ",";
    }
  }
  os << " ]";
  return os;
}