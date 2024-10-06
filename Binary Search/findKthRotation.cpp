#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        int n = arr.size();
        int l = 0;
        int r = n - 1;
        while(l <= r) {
            int mid = l + ((r - l) >> 1);
            if(arr[mid] >= arr[0]) {
                if(mid == n - 1)
                    return 0;
                if(arr[mid] > arr[mid + 1])
                    return mid + 1;
                l = mid + 1;
            }
            else
                r = mid - 1;
        }
        return 0;
    }
};
