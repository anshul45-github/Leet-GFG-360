#include<bits/stdc++.h>
using namespace std;

class Solution {
    void findSubsequences(vector<vector<int>>& combns, vector<int> curr, vector<int>& candidates, int curIdx) {
        combns.push_back(curr);
        if(curIdx == candidates.size()) 
            return;
        
        for(int i = curIdx; i < candidates.size(); i++) {
            if(i != curIdx && candidates[i] == candidates[i - 1])
                continue;
            curr.push_back(candidates[i]);
            findSubsequences(combns, curr, candidates, i + 1);
            curr.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> powerSet;
        vector<int> subset;
        sort(nums.begin(), nums.end());
        findSubsequences(powerSet, subset, nums, 0);
        return powerSet;
    }
};
