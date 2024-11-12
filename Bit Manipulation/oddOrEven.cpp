#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string oddEven(int n) {
        return n & 1 ? "odd" : "even";
    }
};
