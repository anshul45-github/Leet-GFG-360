// https://leetcode.com/problems/h-index-ii/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int low = 0, high = n - 1;
        int ans = 0;
        while(low <= high) {
            int mid = low + ((high - low) >> 1);
            if(citations[mid] >= n - mid) {
                ans = n - mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        return ans;
    }
};