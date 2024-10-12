#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int kthElement(int k, vector<int>& arr1, vector<int>& arr2) {
        int n1 = arr1.size();
        int n2 = arr2.size();
        if(n1 > n2)
            return kthElement(k, arr2, arr1);
        int l = max(0, k - n2);
        int r = min(k, n1);
        // int n = n1 + n2;
        while(l <= r) {
            int mid1 = l + ((r - l) >> 1);
            int mid2 = k - mid1;
            int l1 = INT_MIN, l2 = INT_MIN, r1 = INT_MAX, r2 = INT_MAX;
            if(mid1 - 1 >= 0)
                l1 = arr1[mid1 - 1];
            if(mid2 - 1 >= 0)
                l2 = arr2[mid2 - 1];
            if(mid1 < n1)
                r1 = arr1[mid1];
            if(mid2 < n2)
                r2 = arr2[mid2];
            if(l1 <= r2 && l2 <= r1) {
                return max(l1, l2);
            }
            else if(l1 > r2)
                r = mid1 - 1;
            else
                l = mid1 + 1;
        }
        return 0;
    }
};
