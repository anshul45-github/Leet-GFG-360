#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    long long int floorSqrt(long long int n) {
        long long l = 1;
        long long h = n;
        while(l <= h) {
            long long mid = l + ((h - l) >> 1);
            if(mid * mid == n) {
                return mid;
            }
            else if(mid * mid < n) {
                l = mid + 1;
            }
            else {
                h = mid - 1;
            }
        }
        return h;
    }
};
