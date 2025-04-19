// https://leetcode.com/problems/smallest-palindromic-rearrangement-i/description/
// 3517. Smallest Palindromic Rearrangement I
// Medium

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> freq(26, 0);
        for(int i = 0; i < s.size() / 2; i++)
            freq[s[i] - 'a']++;
        string newStr = "";
        for(int i = 0; i < 26; i++) {
            for(int j = 0; j < freq[i]; j++)
                newStr += 'a' + i;
        }
        string cpy = newStr;
        reverse(newStr.begin(), newStr.end());
        if(s.size() & 1)
            cpy += s[s.size() / 2];
        cpy += newStr;
        return cpy;
    }
};