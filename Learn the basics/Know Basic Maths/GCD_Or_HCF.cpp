// https://www.geeksforgeeks.org/problems/lcm-and-gcd4516/1

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int getGCD(long long a, long long b) {
        if(b == 0)
            return a;
        return getGCD(b, a % b);
    }
  
    vector<long long> lcmAndGcd(long long A , long long B) {
        vector<long long> ans;
        int GCD = getGCD(max(A, B), min(A, B));
        ans.push_back(A * B / GCD);
        ans.push_back(GCD);
        return ans;
    }
};
