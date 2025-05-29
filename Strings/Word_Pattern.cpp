// https://leetcode.com/problems/word-pattern/
// Easy

// Given a pattern and a string s, find if s follows the same pattern.

// Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s.

// Example 1:
// Input: pattern = "abba", s = "dog cat cat dog"
// Output: true

// Example 2:
// Input: pattern = "abba", s = "dog cat cat fish"
// Output: false

// Example 3:
// Input: pattern = "aaaa", s = "dog cat cat dog"
// Output: false

// Example 4:
// Input: pattern = "abba", s = "dog dog dog dog"
// Output: false

#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> mp;
        unordered_set<string> strmp;
        int j = 0;
        for(int i = 0; i < pattern.size(); i++) {
            string temp = "";
            if(j >= s.size())
                return false;
            while(j < s.size() && s[j] != ' ')  {
                temp += s[j];
                j++;
            }
            j++;
            if(!mp.count(pattern[i])) {
                if(strmp.find(temp) != strmp.end())
                    return false;
                strmp.insert(temp);
                mp[pattern[i]] = temp;
            }
            else if(mp[pattern[i]] != temp)
                return false;
        }
        if(j < s.size())
            return false;
        return true;
    }
};