// https://www.geeksforgeeks.org/problems/sum-of-first-n-terms5843/1

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    long long sumOfSeries(long long n) {
        return n * n * (n + 1) * (n + 1) / 4;
    }
};
