#include<bits/stdc++.h>
using namespace std;

class Solution {
    int beauty(vector<int> mp) {
        int maxN = 0;
        int minN = INT_MAX;
        for(int i = 0; i < 26; i++) {
            maxN = max(maxN, mp[i]);
            if(mp[i] != 0)
                minN = min(minN, mp[i]);
        }
        return maxN - minN;
    }
public:
    int beautySum(string s) {
        int ans = 0;
        for(int i = 0; i < s.size(); i++) {
            vector<int> mp(26, 0);
            for(int j = i; j < s.size(); j++) {
                mp[s[j] - 'a']++;
                ans += beauty(mp);
            }
        }
        return ans;
    }
};
