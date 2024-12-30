#include<bits/stdc++.h>
using namespace std;

class cmp {
public:
    bool operator() (pair<int, int> p1, pair<int, int> p2) {
        return p1.second < p2.second;
    }
};

class Twitter {
    int time;
    unordered_map<int, set<int>> following;
    unordered_map<int, vector<pair<int, int>>> tweets;
public:
    Twitter() {
        time = 1;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({tweetId, time});
        time++;
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
        for(int i = 0; i < tweets[userId].size(); i++)
            pq.push(tweets[userId][i]);
        for(set<int>::iterator i = following[userId].begin(); i != following[userId].end(); i++) {
            for(int j = 0; j < tweets[*i].size(); j++) {
                pq.push(tweets[*i][j]);
            }
        }
        vector<int> feed;
        for(int i = 0; i < 10; i++) {
            if(!pq.empty()) {
                feed.push_back(pq.top().first);
                pq.pop();
            }
        }
        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
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
