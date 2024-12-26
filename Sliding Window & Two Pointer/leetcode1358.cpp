#include<bits/stdc++.h>
using namespace std;

class Solution {
    int atMost(string s, int n) {
        unordered_map<char, int> mp;
        int start = 0;
        int ans = 0;
        for(int end = 0; end < s.size(); end++) {
            mp[s[end]]++;
            while(mp.size() > n) {
                mp[s[start]]--;
                if(!mp[s[start]])
                    mp.erase(s[start]);
                start++;
            }
            ans += end - start + 1;
        }
        return ans;
    }
public:
    int numberOfSubstrings(string s) {
        return atMost(s, 3) - atMost(s, 2);
    }
};
