// https://leetcode.com/problems/longest-unequal-adjacent-groups-subsequence-i/
// 2900. Longest Unequal Adjacent Groups Subsequence I
// Easy

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        bool curr = groups[0];
        int j = 1;
        for(int i = 1; i < words.size(); i++) {
            if(groups[i] != curr) {
                words[j] = words[i];
                j++;
                curr = groups[i];
            }
        }
        words.resize(j);
        return words;
    }
};