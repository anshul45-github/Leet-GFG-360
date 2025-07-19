// https://www.geeksforgeeks.org/problems/print-gfg-n-times/1

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void helper(int N, int i) {
        if(i == N)
            return;
        cout << "GFG ";
        helper(N, i + 1);
        return;
    }
  
    void printGfg(int N) {
        helper(N, 0);
        return;
    }
};