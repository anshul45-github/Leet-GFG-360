// TC : O(N), SC : O(1)
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int pairWithMaxSum(vector<int> &arr) {
        int sum;
        int score = INT_MIN;
        for(int i = 0; i < arr.size() - 1; i++) {
            sum = arr[i] + arr[i + 1];
            score = max(score, sum);
        }
        return score;
    }
};
