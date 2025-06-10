// https://leetcode.com/problems/maximum-difference-between-even-and-odd-frequency-i/
// Easy

#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char, int> mp;
        for(char ch : s) 
            mp[ch]++;
        int maxi = 0;
        int mini = 98;
        for(auto& p : mp) {
            if(p.second % 2)
                maxi = max(maxi, p.second);
            else
                mini = min(mini, p.second);
        }
        return maxi - mini;
    }
};