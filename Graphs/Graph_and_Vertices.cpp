// https://www.geeksforgeeks.org/problems/graph-and-vertices/1

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    long long count(int n) {
        return 1LL << ((n * (n - 1)) / 2);
    }
};