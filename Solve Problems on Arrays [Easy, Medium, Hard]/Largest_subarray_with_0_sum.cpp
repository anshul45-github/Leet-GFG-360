// https://www.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxLen(vector<int>& arr, int n) {
        int maxLen = 0;
        int currSum = 0;
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++) {
            currSum += arr[i];
            if(!mp[currSum])
                mp[currSum] = i + 1;
            if(currSum == 0)
                maxLen = max(maxLen, i + 1);
            if(mp[currSum])
                maxLen = max(maxLen, i - mp[currSum] + 1);
        }
        return maxLen;
    }
};
