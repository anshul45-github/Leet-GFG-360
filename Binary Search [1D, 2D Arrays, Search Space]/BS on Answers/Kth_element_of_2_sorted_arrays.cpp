// https://www.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int kthElement(vector<int>& a, vector<int>& b, int k) {
        if(a.size() > b.size())
            return kthElement(b, a, k);
        int low = max(0, k - (int)b.size()), high = min(k, (int)a.size());
        // int prev = k - 1;
        while(low <= high) {
            int mid1 = low + ((high - low) >> 1);
            int mid2 = k - mid1;
            int l1 = (mid1 >= 1) ? a[mid1 - 1] : INT_MIN;
            int l2 = (mid2 >= 1) ? b[mid2 - 1] : INT_MIN;
            int r1 = (mid1 < a.size()) ? a[mid1] : INT_MAX;
            int r2 = (mid2 < b.size()) ? b[mid2] : INT_MAX;
            if(l1 <= r2 && l2 <= r1) 
                return max(l1, l2);
            else if(l1 <= r2)
                low = mid1 + 1;
            else
                high = mid1 - 1;
        }
        return -1;
    }
};