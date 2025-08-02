// https://leetcode.com/problems/design-twitter/

#include<bits/stdc++.h>
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