// https://leetcode.com/problems/permutation-in-string/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool checkInclusion(string s1, string s2) {
            unordered_map<int, int> o;
            unordered_map<int, int> t;
            for(char ch : s1)
                o[ch]++;
            int l = 0;
            int r = 0;
            while(r < s2.size()) {
                if(!o.count(s2[r])) {
                    t.clear();
                    l = r + 1;
                    r++;
                }
                else {
                    t[s2[r]]++;
                    while(t[s2[r]] > o[s2[r]]) {
                        t[s2[l]]--;
                        l++;
                    }
                    if(r - l + 1 == s1.size())
                        return true;
                    r++;
                }
            }
            return false;
        }
    };