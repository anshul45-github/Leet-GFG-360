// https://www.geeksforgeeks.org/problems/ncr1019/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int nCr(int n, int r) {
        if(r == 0)
            return 1;
        return nCr(n - 1, r - 1) * (double)n / r;
    }
};