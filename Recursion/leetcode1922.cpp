#include<bits/stdc++.h>
using namespace std;

#define N 1000000007

class Solution {
    long long myPow(long long x, long long n) {
        if(n == 0) return 1;
        long long ans = myPow(x, n / 2);
        ans *= ans;
        ans %= N;
        if(n & 1)
            ans *= x;
        ans %= N;
        return ans;
    }
public:
    int countGoodNumbers(long long n) {
        long long odd = n / 2;
        long long even = (n / 2) + (n & 1);
        return (myPow(5, even) * myPow(4, odd)) % N;
    }
};
