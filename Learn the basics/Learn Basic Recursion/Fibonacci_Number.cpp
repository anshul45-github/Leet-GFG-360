// https://leetcode.com/problems/fibonacci-number/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int fib(int n) {
        if(n == 0)
            return 0;
        if(n == 1)
            return 1;
        return fib(n - 1) + fib(n - 2);
    }
};
