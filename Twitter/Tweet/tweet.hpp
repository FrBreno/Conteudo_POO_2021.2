#include <iostream>
#include <set>

class Tweet
{
private:
  int id{-1};
  std::set<std::string> likes;
  std::string userName{};
  std::string msg{};
  Tweet *rt{nullptr};
  bool deleted{false};

public:
  Tweet(int id, const std::string &userName, const std::string &msg);
  int getId() const;
  std::string getSender() const;
  std::string getMsg() const;

  void like(const std::string &username);
  std::set<std::string> getLikes() const;

  void setRt(Tweet *rt);

  void setDeleted();
  bool isDeleted() const;

  friend std::ostream &operator<<(std::ostream &os, const Tweet &mes);
};
