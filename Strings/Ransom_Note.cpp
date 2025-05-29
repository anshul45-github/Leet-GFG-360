// https://leetcode.com/problems/ransom-note/
// Easy

// Given two strings ransomNote and magazine, return true if ransomNote can be constructed from magazine and false otherwise.

// Each letter in magazine can only be used once in ransomNote.

// Example 1:
// Input: ransomNote = "a", magazine = "b"
// Output: false

// Example 2:
// Input: ransomNote = "aa", magazine = "ab"
// Output: false

// Example 3:
// Input: ransomNote = "aa", magazine = "aab"
// Output: true

#include<string>
#include<unordered_map>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> mp;
        for(int i = 0; i < magazine.size(); i++)
            mp[magazine[i]]++;
        for(int i = 0; i < ransomNote.size(); i++) {
            if(mp[ransomNote[i]] == 0)
                return false;
            mp[ransomNote[i]]--;
        }
        return true;
    }
};