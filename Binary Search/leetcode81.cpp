#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool binarySearch(vector<int> v, int target) {
        int l = 0;
        int h = v.size() - 1;
        while(l <= h) {
            int mid = l + (h - l) / 2;
            if(v[mid] == target)
                return true;
            if(target < v[mid])
                h = mid - 1;
            else
                l = mid + 1;
        }
        return false;
    }
    bool search(vector<int>& nums, int target) {
        vector<int> v;
        int pivot = 0;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] < nums[i - 1]) {
                pivot = i;
                break;
            }
        }
        for(int i = pivot; i < nums.size(); i++)
            v.push_back(nums[i]);
        for(int i = 0; i < pivot; i++)
            v.push_back(nums[i]);
        return binarySearch(v, target);
    }
};
