// https://leetcode.com/problems/longest-binary-subsequence-less-than-or-equal-to-k/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubsequence(string s, int k) {
        int num = 0;
        int maxi = 0;
        for(int i = s.size() - 1, cnt = 0; i >= 0 && cnt <= 29; i--, cnt++) {
            if(s[i] == '1' && (num + (1 << cnt)) <= k) {
                num = num + (1 << cnt);
                maxi = max(maxi, cnt + 1);
            }
        }
        for(int i = s.size() - maxi; i >= 0; i--) {
            if(s[i] == '0')
                maxi++;
        }
        return maxi;
    }
};