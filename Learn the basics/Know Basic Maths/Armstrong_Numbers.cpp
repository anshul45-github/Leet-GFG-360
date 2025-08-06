// https://www.geeksforgeeks.org/problems/armstrong-numbers2727/1

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool armstrongNumber(int n) {
        int ans = n;
        while(n) {
            int d = n % 10;
            n /= 10;
            ans -= d * d * d;
        }
        return ans == 0;
    }
};