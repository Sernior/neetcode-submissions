#include <ranges>
class Twitter {
public:
    Twitter() = default;
    
    void postTweet(int userId, int tweetId) {
        auto& t = tweets_[userId];
        t.push_back({c_, tweetId});
        std::ranges::push_heap(t);
        ++c_;
    }
    
vector<int> getNewsFeed(int userId) {
    vector<pair<TweetTime, TweetId>> ret;
    auto take10 = [&](UserId u) {
        auto tweets = tweets_[u];
        for (int i = 0; i < 10; ++i) {
            if (tweets.empty()) break;
            ranges::pop_heap(tweets);
            ret.push_back(tweets.back());
            ranges::push_heap(ret);
            tweets.pop_back();
        }
    };
    take10(userId);
    for (auto followee : followees_[userId]) {
        take10(followee);
    }

    vector<int> feed;
    for (int i = 0; i < 10; ++i) {
        if (ret.empty()) break;
        ranges::pop_heap(ret);
        feed.push_back(ret.back().second);
        ret.pop_back();
    }
    return feed;
}
    
    void follow(int followerId, int followeeId) {
        if (followerId == followeeId)return;
        if (std::ranges::find(followees_[followerId], followeeId) !=
            followees_[followerId].end())return;
        followees_[followerId].push_back(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        std::erase(followees_[followerId], followeeId);
    }

private:
    using TweetTime = uint32_t;
    TweetTime c_{};
    using UserId = int;
    using TweetId = int;
    std::unordered_map<UserId, std::vector<pair<TweetTime, TweetId>>> tweets_;
    unordered_map<UserId, vector<UserId>> followees_;
};
