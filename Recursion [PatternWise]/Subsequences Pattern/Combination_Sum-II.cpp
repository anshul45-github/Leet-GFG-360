// https://leetcode.com/problems/combination-sum-ii/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool checkDuplicates(vector<vector<int>>& ans, vector<int>& curr) {
        for(auto& v : ans) {
            if(v == curr)
                return true;
        }
        return false;
    }
    void solve(vector<int>& candidates, int target, int i, vector<vector<int>>& ans, vector<int> curr) {
        if(target == 0) {            
            if(!checkDuplicates(ans, curr))
                ans.push_back(curr);;
            return;
        }
        if(target < 0 || i == candidates.size())
            return;
        for(int idx = i; idx < candidates.size(); idx++) {
            if(i != idx && candidates[idx] == candidates[idx - 1])
                continue;
            curr.push_back(candidates[idx]);
            solve(candidates, target - candidates[idx], idx + 1, ans, curr);
            curr.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> curr;
        vector<vector<int>> ans;
        sort(candidates.begin(), candidates.end());
        solve(candidates, target, 0, ans, curr);
        return ans;
    }
};