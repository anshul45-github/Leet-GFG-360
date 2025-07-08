// https://leetcode.com/problems/fruit-into-baskets/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int left = 0;
        unordered_map<int, int> mp;
        int ans = 0;
        for(int right = 0; right < fruits.size(); right++) {
            mp[fruits[right]]++;
            while(mp.size() > 2) {
                if(--mp[fruits[left]] == 0)
                    mp.erase(fruits[left]);
                left++;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};