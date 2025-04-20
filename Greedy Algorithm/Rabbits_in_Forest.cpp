// https://leetcode.com/problems/rabbits-in-forest/
// 781. Rabbits in Forest
// Medium

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> mp;
        int ans = 0;
        for(int i = 0; i < answers.size(); i++) {
            if(mp[answers[i]] == 0)
                ans += answers[i] + 1;
            mp[answers[i]]++;
            mp[answers[i]] %= answers[i] + 1;
        }
        return ans;
    }
};