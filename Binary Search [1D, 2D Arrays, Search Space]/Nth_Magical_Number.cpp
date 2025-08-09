// https://leetcode.com/problems/nth-magical-number/
// Hard

// This code is a solution to the problem of finding the N-th magical number given two integers A and B.

// The magical numbers are defined as the numbers that are multiples of either A or B.

#include<bits/stdc++.h>
#include<numeric>
using namespace std;

class Solution {
    int magicNumbersLessEqual(long x, int A, int B, int LCM) {
        return (x/A) + (x/B) - (x/LCM); 
    }
public:
    const int MOD = 1e9+7;
    int nthMagicalNumber(int N, int A, int B) {
        long LCM = lcm(A, B), L = min(A, B), R = N * L, mid, ans;
        while(L <= R) {
            mid = L + (R - L) / 2;
            if(magicNumbersLessEqual(mid, A, B, LCM) < N) 
                L = mid + 1;
            else {
                R = mid - 1;
                ans = mid;
            }
        }
        return ans % MOD;
    }
};