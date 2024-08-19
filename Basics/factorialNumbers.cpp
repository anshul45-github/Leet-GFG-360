// TC : O(K), SC : O(1)
// K -> no of factorial numbers

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<long long> factorialNumbers(long long n) {
        int i = 2;
        long long k = 1;
        vector<long long> nums;
        while(k <= n) {
            nums.push_back(k);
            k *= i;
            i++;
        }
        return nums;
    }
};
