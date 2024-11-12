#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int findXOR(int l, int r) {
        bool lI = false;
        bool rD = false;
        if(l & 1) {
            lI = true;
            l++;
        }
        if(!(r & 1)) {
            rD = true;
            r--;
        }
        int ans = 0;
        if(((r - l + 1) >> 1) & 1) {
            ans++;
        }
        if(lI)
            ans = ans ^ --l;
        if(rD)
            ans = ans ^ ++r;
        return ans;
    }
};
