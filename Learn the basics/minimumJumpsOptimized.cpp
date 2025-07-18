// TC : O(N), SC : O(1)

#include<bits/stdc++.h>
using namespace std;

class Solution{
  public:
    int minJumps(int arr[], int n) {
        int l = 0;
        int r = 0;
        int jumps = 0;
        while(r < n - 1) {
            int maxJump = -1;
            bool allZeroes = true;
            for(int i = l; i <= r; i++) {
                maxJump = max(maxJump, arr[i] + i);
                if(arr[i] != 0)
                    allZeroes = false;
            }
            if(allZeroes)
                return -1;
            l = r + 1;
            r = maxJump;
            jumps++;
        }
        return jumps;
    }
};
