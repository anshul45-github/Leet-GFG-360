// https://leetcode.com/problems/power-of-two/
// 231. Power of Two
// Easy

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0)
            return false;
        return !(n & (n - 1));
    }
};
