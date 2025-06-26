// https://www.geeksforgeeks.org/problems/find-nth-root-of-m5843/1

#include<bits/stdc++.h>
using namespace std;

class Solution {
    int isValid(int x, int n, int m) {
        long long p = 1;
        for(int i = 0; i < n; i++) {
            p *= x;
            if(p > 1LL * m)
                return -1;
            
        }
        // cout << x << " " << p << endl;
        if(p == m)
            return 0;
        return 1;
    }
  public:
    int nthRoot(int n, int m) {
        int low = 1, high = m;
        while(low <= high) {
            int mid = low + ((high - low) >> 1);
            int e = isValid(mid, n, m);
            // cout << mid << " " << e << endl;
            if(e == 0)
                return mid;
            else if(e == 1)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return -1;
    }
};