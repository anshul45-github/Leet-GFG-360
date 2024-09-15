// TC : O(N), SC : O(N)
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        int maxLen = 0;
        int currSum = 0;
        unordered_map<int, int> mp;
        for(int i = 0; i < N; i++) {
            currSum += A[i];
            if(!mp[currSum])
                mp[currSum] = i + 1;
            if(currSum == K)
                maxLen = max(maxLen, i + 1);
            if(mp[currSum - K]) {
                maxLen = max(maxLen, i - mp[currSum - K] + 1);
            }
        }
        return maxLen;
    }
};
