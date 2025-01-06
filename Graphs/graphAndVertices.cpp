// TC : O(1), SC : O(1)
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    long long count(int n) {
        long long total_edges = n * (n - 1) / 2;
        return pow(2, total_edges);
    }
};
