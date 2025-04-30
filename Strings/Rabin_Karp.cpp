// https://leetcode.com/problems/repeated-string-match/
// 686. Repeated String Match
// Medium

#include<bits/stdc++.h>
using namespace std;

#define N 1000000007

class Solution {
    bool rabin_karp(string& a, int& m, long long& hashCode, string& b) {
        long long textHash = 0;
        long long p_curr = 1;
        for(int i = 0; i < m; i++) {
            p_curr *= 31;
            p_curr %= N;
        }
        for(int i = 0; i < a.size(); i++) {
            textHash *= 31;
            textHash += a[i];
            textHash %= N;
            if(i >= m) {
                textHash -= a[i - m] * p_curr;
                textHash %= N;
                if(textHash < 0)
                    textHash += N;
            }
            if(i >= m - 1) {
                if(hashCode == textHash) {
                    if(a.substr(i - m + 1, m) == b)
                        return true;
                }
            }
        }
        return false;
    }
public:
    int repeatedStringMatch(string a, string b) {
        long long patternHash = 0;
        for(int i = 0; i < b.size(); i++) {
            patternHash *= 31;
            patternHash += b[i];
            patternHash %= N;
        }
        string modifyA = a;
        int cnt = 1;
        while(modifyA.size() < b.size()) {
            modifyA += a;
            cnt++;
        }
        int m = b.size();
        if(rabin_karp(modifyA, m, patternHash, b))
            return cnt;
        modifyA += a;
        if(rabin_karp(modifyA, m, patternHash, b))
            return cnt + 1;
        return -1;
    }
};
