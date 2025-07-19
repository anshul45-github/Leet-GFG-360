// https://www.geeksforgeeks.org/problems/pass-by-reference-and-value/1

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> passedBy(int a, int &b) {
        vector<int> v;
        v.push_back(a + 1);
        v.push_back(b + 2);
        return v;
    }
};
