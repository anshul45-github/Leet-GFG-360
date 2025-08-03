//https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char, int> mp;
        int l = 0;
        int r = 0;
        int zeroOccurrence = 0;
        while(r < s.size()) {
            mp[s[r]]++;
            while(mp['a'] && mp['b'] && mp['c']) {
                mp[s[l]]--;
                l++;
            }
            zeroOccurrence += r - l + 1;
            r++;
        }
        long long total = s.size() * (s.size() + 1) / 2;
        return total - zeroOccurrence;
    }
};