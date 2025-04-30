// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/
// 1392. Longest Happy Prefix
// Hard

#include<bits/stdc++.h>
using namespace std;

#define N 1000000007

class Solution {
public:
    string longestPrefix(string s) {
        int maxI = -1;
        long long hash = 0;
        long long revHash = 0;
        long long p_curr = 1;
        for(int i = 0; i < s.size() - 1; i++) {
            hash = (hash * 31 + s[i]) % N;
            revHash = (revHash + p_curr * s[s.size() - i - 1]) % N;
            p_curr = (p_curr * 31) % N;
            if(hash == revHash)
                maxI = i;
        }
        return s.substr(0, maxI + 1);
    }
};
