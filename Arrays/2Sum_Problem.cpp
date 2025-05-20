// TC < O(N)
#include<bits/stdc++.h>
using namespace std;

class Solution {
    int binarySearch(vector<int> arr, int size, int target) {
        int left = 0, right = size - 1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(arr[mid] == target) {
                return mid;
            }
            if(arr[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
    
        return -1;
    }
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> num;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            int idx = binarySearch(nums, n, target - nums[i]);
            if(idx != -1) {
                vector<int> a = {i, idx};
                return a;
            }
        }
        vector<int> v;
        return v;
    }
};
