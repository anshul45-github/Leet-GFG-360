// https://www.geeksforgeeks.org/problems/calculate-the-coefficient/1

#include<bits/stdc++.h>
using namespace std;

class Solution {
    const int N = 1e9 + 7;
  public:
    int permutationCoeff(int n, int k) {
        long long val = 1;
        for(int i = n - k + 1; i <= n; i++)
            val = (val * i) % N;
        return val;
    }
};