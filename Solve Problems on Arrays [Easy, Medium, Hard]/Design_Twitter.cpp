// https://leetcode.com/problems/design-twitter/
// Medium

// Design a simplified version of Twitter where users can post tweets, follow/unfollow another user, and get the 10 most recent tweets in the user's news feed.

// Implement the Twitter class:

// Twitter() Initializes your twitter object.

// void postTweet(int userId, int tweetId) Composes a new tweet with ID tweetId by the user userId.

// List<Integer> getNewsFeed(int userId) Retrieves the 10 most recent tweet IDs in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user themselves. Tweets must be ordered from most recent to least recent.

// If there are fewer than 10 tweets in the news feed, return the ten most recent tweets.

// void follow(int followerId, int followeeId) The user with ID followerId now follows the user with ID followeeId.

// void unfollow(int followerId, int followeeId) The user with ID followerId unfollows the user with ID followeeId.

// Constraints:
// 1 <= userId, followerId, followeeId <= 500
// 0 <= tweetId <= 10^4
// All the tweets have unique IDs.
// At most 3 * 10^4 calls will be made to postTweet, getNewsFeed, follow, and unfollow.
// Followee and follower IDs are always different.

#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;

class Twitter {
    unordered_map<int, unordered_set<int>> followersMap;
    unordered_map<int, vector<pair<int, int>>> tweetsMap;
    int time;
public:
    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweetsMap[userId].push_back({time, tweetId});
        time++;
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<pair<int, int>> v;
        for(auto& following : followersMap[userId]) {
            for(int i = tweetsMap[following].size() - 1; i >= max((int)tweetsMap[following].size() - 10, 0); i--) {
                auto tweet = tweetsMap[following][i];
                v.push_back(tweet);
            }
        }
        for(int i = tweetsMap[userId].size() - 1; i >= max((int)tweetsMap[userId].size() - 10, 0); i--)
            v.push_back(tweetsMap[userId][i]);
        sort(v.begin(), v.end());
        vector<int> ans;
        for(int i = v.size() - 1; i >= max((int)v.size() - 10, 0); i--)
            ans.push_back(v[i].second);
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        followersMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followersMap[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */