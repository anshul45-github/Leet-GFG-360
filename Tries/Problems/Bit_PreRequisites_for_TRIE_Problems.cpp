// TC : O(1), SC : O(1)
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int XOR(int n, int m) {
        return n ^ m;
    }
    int check(int a, int b) {
        return (((1 << (a - 1)) & b) != 0);
    }
    int setBit(int c, int d) {
        d = d | (1 << c);
        return d;
    }
};
