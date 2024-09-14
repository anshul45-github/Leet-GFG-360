#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void swap(vector<int>& nums, int i, int j) {
        int k = nums[i];
        nums[i] = nums[j];
        nums[j] = k;
    }
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int m = nums[n - 1];
        int j = n - 2;
        while(j >= 0) {
            if(nums[j] < m) {
                break;
            }
            m = nums[j];
            j--;
        }
        if(j == -1) {
            sort(nums.begin(), nums.end());
            return;
        }
        int mi = j + 1;
        cout << mi << endl;
        for(int i = j + 2; i < n; i++) {
            if(nums[i] < nums[mi] && nums[i] > nums[j])
                mi = i;
        }
        cout << mi << endl;
        swap(nums, j, mi);
        sort(nums.begin() + j + 1, nums.end());
    }
};
