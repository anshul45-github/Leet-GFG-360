#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int evenlyDivides(int N){
        int M = N;
        int ans = 0;
        while(M > 0) {
            int d = M % 10;
            if(N % d == 0)
                ans++;
            M = (int)(M / 10);
        }
        return ans;
    }
};
