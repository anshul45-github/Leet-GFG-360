// Using recursion, but it gives TLE, as without dp it is not possible to solve.
#include<bits/stdc++.h>
using namespace std;

class Solution {
    int findSubsequences(vector<int>& arr, int target, int i, int sum) {
        if(i == arr.size())
            return sum == target ? 1 : 0;
        if(sum > target)
            return 0;
        return findSubsequences(arr, target, i + 1, sum) + 
        findSubsequences(arr, target, i+ 1, sum + arr[i]);
    }
  public:
    int perfectSum(vector<int>& arr, int target) {
        return findSubsequences(arr, target, 0, 0);
    }
};
