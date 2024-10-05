#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to find floor of x
    // n: size of vector
    // x: element whose floor is to find
    int findFloor(vector<long long> &v, long long n, long long x) {
        int l = 0;
        int r = n - 1;
        while (l <= r) {
            int mid = l + ((r - l) >> 1);
            if (v[mid] == x) {
                return mid; // Found the exact element
            } else if (v[mid] < x) {
                l = mid + 1; // Move to the right half
            } else {
                r = mid - 1; // Move to the left half
            }
        }
        return r;
    }
};
