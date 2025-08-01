// https://leetcode.com/problems/count-good-numbers/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    const int mod = 1e9 + 7;
    long long myPow(int x, long long n) {
        if(n == 0)
            return 1;
        long long a = myPow(x, n >> 1) % mod;
        if(n & 1)
            return (a * a * x) % mod;
        return (a * a) % mod;
    }
public:
    int countGoodNumbers(long long n) {
        long long evenIndices = n >> 1;
        if(n & 1)
            evenIndices++;
        long long oddIndices = n >> 1;
        return (myPow(4, oddIndices) * myPow(5, evenIndices)) % mod;
    }
};