// https://leetcode.com/problems/candy/

#include<bits/stdc++.h>
using namespace std;

// Approach 1: Two-pass greedy algorithm
class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> candies(ratings.size());
        candies[0] = 1;
        for(int i = 1; i < ratings.size(); i++) {
            if(ratings[i] > ratings[i - 1])
                candies[i] = candies[i - 1] + 1;
            else
                candies[i] = 1;
        }
        vector<int> candiesr(ratings.size());
        candiesr.back() = 1;
        for(int i = ratings.size() - 2; i >= 0; i--) {
            if(ratings[i] > ratings[i + 1])
                candiesr[i] = candiesr[i + 1] + 1;
            else
                candiesr[i] = 1;
        }
        int ans = 0;
        for(int i = 0; i < ratings.size(); i++)
            ans += max(candies[i], candiesr[i]);
        return ans;
    }
};

// Approach 2: One-pass greedy algorithm
class Solution {
public:
    int candy(vector<int>& ratings) {
        int sum = 1;
        int i = 1;
        while(i < ratings.size()) {
            if(ratings[i] == ratings[i - 1]) {
                i++;
                sum++;
                continue;
            }
            int peak = 1;
            while(i < ratings.size() && ratings[i] > ratings[i - 1]) {
                peak++;
                sum += peak;
                i++;
            }
            int down = 1;
            while(i < ratings.size() && ratings[i] < ratings[i - 1]) {
                sum += down;
                i++;
                down++;
            }
            if(down > peak)
                sum += down - peak;
        }
        return sum;
    }
};