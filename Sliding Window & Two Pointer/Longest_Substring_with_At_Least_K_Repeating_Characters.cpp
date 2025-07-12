// https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    int solve(string& s, int u, int k) {
        int cnt = 0, cnt_k = 0;
        int start = 0;
        unordered_map<char, int> mp;
        int ans = 0;
        for(int end = 0; end < s.size(); end++) {
            if(++mp[s[end]] == 1)
                cnt++;
            if(mp[s[end]] == k)
                cnt_k++;
            while(cnt > u) {
                if(mp[s[start]]-- == k)
                    cnt_k--;
                if(mp[s[start]] == 0)
                    cnt--;
                start++;
            }
            if(cnt == u && cnt_k == u)
                ans = max(ans, end - start + 1);
        }
        return ans;
    }
public:
    int longestSubstring(string s, int k) {
        unordered_set<char> st(s.begin(), s.end());
        int unique = st.size();
        int maxlen = 0;
        for(int u = 1; u <= unique; u++) 
            maxlen = max(maxlen, solve(s, u, k));
        return maxlen;
    }
};