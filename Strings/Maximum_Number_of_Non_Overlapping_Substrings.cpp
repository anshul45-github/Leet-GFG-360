// https://leetcode.com/problems/maximum-number-of-non-overlapping-substrings/
// Hard

// Given a string s, return the maximum number of non-overlapping substrings of s such that each substring is a substring of s and contains all occurrences of its characters.

// A substring is a contiguous sequence of characters in a string.

#include<string>
#include<unordered_map>
#include<vector>
using namespace std;

class Solution {
    int checkSubstr(string& s, int i, unordered_map<char, int>& start, unordered_map<char, int>& end) {
        int right = end[s[i]];
        for(int idx = i; idx <= right; idx++) {
            if(start[s[idx]] < i)
                return -1;
            right = max(right, end[s[idx]]);
        }
        return right;
    }
public:
    vector<string> maxNumOfSubstrings(string s) {
        unordered_map<char, int> start;
        unordered_map<char, int> end;
        for(int i = 0; i < s.size(); i++) {
            char ch = s[i];
            if(!start.count(ch))
                start[ch] = i;
            end[ch] = i;
        }
        int right = -1;
        vector<string> ans;
        for(int i = 0; i < s.size(); i++) {
            if(i == start[s[i]]) {
                int newRight = checkSubstr(s, i, start, end);
                if(newRight == -1)
                    continue;
                if(i > right)
                    ans.push_back("");
                right = newRight;
                ans.back() = s.substr(i, right - i + 1);
            }
        }
        return ans;
    }
};