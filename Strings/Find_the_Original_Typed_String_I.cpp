// https://leetcode.com/problems/find-the-original-typed-string-i/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int possibleStringCount(string word) {
        int ans = 0;
        char ch = word[0];
        int freq = 0;
        for(int i = 0; i < word.size(); i++) {
            if(word[i] == ch)
                freq++;
            else {
                ch = word[i];
                ans += freq - 1;
                freq = 1;
            }
        }
        return ans + freq;
    }
};