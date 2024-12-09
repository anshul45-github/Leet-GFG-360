// TC : O(logn), SC : O(1)
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int countSetBits(int n) {
        if(n == 0)
            return 0;
        
        int cnt = 0;
        
        while(n) {
            int x = 1;
            int power = 0;
            while((x << 1) <= n) {
                x = x << 1;
                power++;
            }
            cnt += power * x / 2;
            cnt += n - x + 1;
            n = n - x;
        }
        return cnt;
    }
};
