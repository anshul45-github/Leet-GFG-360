#include<bits/stdc++.h>
using namespace std;

class Solution {
    static bool cmp(string a, string b) {
        return a.size() < b.size();
    }
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), cmp);
        int maxi = 1;
        unordered_map<string, int> dp;
        for(int i = 0; i < words.size(); i++) {
            string curr = words[i];
            dp[curr] = 1;
            for(int k = 0; k < curr.size(); k++) {
                string pred = curr.substr(0, k) + curr.substr(k + 1);
                if(dp.count(pred))
                    dp[curr] = max(dp[curr], dp[pred] + 1);
            }
            maxi = max(maxi, dp[curr]);
        }
        return maxi;
    }
};

// To do in same pattern as Longest Increasing Subsequence
class Solution {
    static bool cmp(string s1, string s2) {
        return s1.size() < s2.size();
    }
    bool isPredecessor(string& p, string& s) {
        int i = 0, j = 0;
        while(i < p.size() && j < s.size() && s[j] == p[i]) {
            i++;
            j++;
        }
        j++;
        while(i < p.size() && j < s.size() && p[i] == s[j]) {
            i++;
            j++;
        }
        return i == p.size() && j == s.size();
    }
public:
    int longestStrChain(vector<string>& arr) {
        sort(arr.begin(), arr.end(), cmp);
        vector<int> dp(arr.size(), 1);
        int lenlis = 1;
        for(int i = 0; i < arr.size(); i++) {
            for(int j = 0; j < i; j++) {
                if(isPredecessor(arr[j], arr[i]) && dp[j] + 1 > dp[i]) 
                    dp[i] = dp[j] + 1;
            }
            if(dp[i] > lenlis) 
                lenlis = dp[i];
        }
        return lenlis;
    }
};