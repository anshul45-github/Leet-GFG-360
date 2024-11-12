#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        long ans = 0;
        bool sign = (divisor >= 0) ^ (dividend < 0);
        long n = labs(dividend);
        long d = labs(divisor);
        while(n >= d) {
            long cnt = 0;
            while(n >= (d << (cnt + 1))) {
                cnt++;
            }
            ans += 1 << cnt;
            n -= d << cnt;
        }
        return (int)(sign ? ans : -ans);
    }
};
