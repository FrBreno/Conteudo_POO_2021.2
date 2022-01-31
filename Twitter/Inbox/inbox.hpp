#include "../Tweet/tweet.hpp"
#include <map>
#include <vector>
#include <memory>

class Inbox
{
private:
  std::map<int, Tweet *> timeline;
  std::map<int, Tweet *> myTweets;

public:
  Inbox();
  void storeInTimeline(Tweet *tweet);
  void storeInMyTweets(Tweet *tweet);
  std::vector<Tweet *> getTimeline() const;
  std::vector<Tweet *> getMyTweets() const;
  Tweet *getTweet(int id);
  void rmMsgsFrom(const std::string &username);

  friend std::ostream &operator<<(std::ostream &os, Inbox &in);
};