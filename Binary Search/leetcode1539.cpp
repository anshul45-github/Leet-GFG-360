#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int l = 0;
        int h = n - 1;
        pair<int, int> p;
        while(l <= h) {
            int mid = l + ((h - l) >> 1);
            int m = arr[mid] - mid - 1;
            p.first = arr[mid];
            p.second = m;
            if(m < k) {
                l = mid + 1;
            }
            else {
                h = mid - 1;
            }
        }
        if(p.second > k) {
            p.first -= (p.second - k + 1);
        }
        else if(p.second == k) {
            p.first--;
        }
        else
            p.first += (k - p.second);
        return p.first;
    }
};
