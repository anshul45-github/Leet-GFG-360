// https://leetcode.com/problems/find-two-non-overlapping-sub-arrays-each-with-target-sum/

#include<vector>
#include<climits>
using namespace std;

class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int l = 0;
        int sum = 0;
        vector<int> pre(arr.size() + 1, 1e9);
        vector<int> suf(arr.size(), 1e9);
        for(int r = 0; r < arr.size(); r++) {
            sum += arr[r];
            while(sum > target) {
                sum -= arr[l];
                l++;
            }
            if(sum == target) {
                pre[r + 1] = r - l + 1;
                suf[l] = r - l + 1;
            }
        }
        for(int i = 1; i < arr.size() + 1; i++) 
            pre[i] = min(pre[i - 1], pre[i]);
        for(int i = arr.size() - 2; i >= 0; i--)
            suf[i] = min(suf[i + 1], suf[i]);
        int ans = INT_MAX;
        for(int i = 0; i < arr.size(); i++) {
            if(pre[i] == 1e9 || suf[i] == 1e9)
                continue;
            ans = min(ans, pre[i] + suf[i]);
        }
        if(ans == INT_MAX)
            return -1;
        return ans;
    }
};