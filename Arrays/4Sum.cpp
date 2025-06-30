// https://leetcode.com/problems/4sum/

#include<bits/stdc++.h>
using namespace std;

// Brute Force Approach (TLE)
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        set<vector<int>> set;
        vector<vector<int>> output;
        for(int i=0; i < n - 3; i++) {
            for(int j = i + 1; j < n - 2; j++) {
                for(int k = j + 1; k < n - 1; k++) {
                    for(int l = k + 1; l < n; l++) {
                        if((long long)nums[i] + (long long)nums[j] + (long long)nums[k] + (long long)nums[l] == target) 
                            set.insert({nums[i], nums[j], nums[k], nums[l]});
                    }
                }
            }
        }
        for(auto it : set) {
            output.push_back(it);
        }
        return output;
    }
};

// Better Approach: Hashing
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        set<vector<int>> set;
        vector<vector<int>> output;
        for(int i = 0; i < n - 3; i++) {
            for(int j = i + 1; j < n - 2; j++) {
                long long newTarget = (long long)target - (long long)nums[i] - (long long)nums[j];
                int low = j + 1, high = n - 1;
                while(low < high) {
                    if(nums[low] + nums[high] < newTarget)
                        low++;
                    else if(nums[low] + nums[high] > newTarget)
                        high--;
                    else {
                        set.insert({nums[i], nums[j], nums[low], nums[high]});
                        low++; 
                        high--;
                    }
                }
            }
        }
        for(auto it : set)
            output.push_back(it);
        return output;
    }
};

// Optimised Approach: Two Pointer Technique
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n; i++) {
            if(i > 0 && nums[i] == nums[i - 1])
                continue;
            for(int j = i + 1; j < n; j++) {
                if(j != i + 1 && nums[j] == nums[j - 1]) 
                    continue;
                int k = j + 1;
                int l = n - 1;
                while(k < l) {
                    long long sum = 1LL * nums[i] + 1LL * nums[j] + 1LL * nums[k] + 1LL * nums[l];
                    if(sum == target) {
                        vector<int> a = {nums[i], nums[j], nums[k], nums[l]};
                        ans.push_back(a);
                        k++;
                        l--;
                        while(nums[k] == nums[k - 1] && k < l) 
                            k++;
                        while(k < l && nums[l] == nums[l + 1]) 
                            l--;
                    }
                    else if(sum < target) 
                        k++;
                    else 
                        l--;
                }
            }
        }
        return ans;
    }
};