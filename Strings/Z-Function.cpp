// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/
// 28. Find the Index of the First Occurence in a String
// Easy

#include<string>
using namespace std;

#define N 1000000007

class Solution {
public:
    int strStr(string& badi, string& choti) {
        long long hashCode = 0;
        for(int i = 0; i < choti.size(); i++) {
            hashCode *= 31;
            hashCode += choti[i];
            hashCode %= N;
        }
        long long badiHash = 0;
        int m = choti.size();
        long long p_curr = 1;
        for(int i = 0; i < m; i++)
            p_curr = (p_curr * 31) % N;
        for(int i = 0; i < badi.size(); i++) {
            badiHash *= 31;
            badiHash += badi[i];
            badiHash %= N;
            if(i >= m) {
                badiHash -= p_curr * badi[i - m];
                badiHash %= N;
                if(badiHash < 0)
                    badiHash += N;
            }
            if(i >= m - 1) {
                if(badiHash == hashCode) {
                    if(badi.substr(i - m + 1, m) == choti)
                        return i - m + 1;
                }
            }
        }
        return -1;
    }
};
