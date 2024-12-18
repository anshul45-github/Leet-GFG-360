#include<bits/stdc++.h>
using namespace std;

class Solution {
    void findSubsequences(vector<vector<int>>& combns, vector<int> curr, vector<int>& candidates, int sum, int target, int curIdx) {
        if(sum == target) {
            combns.push_back(curr);
            return;
        }
        if(curIdx == candidates.size() || sum > target) {
            return;
        }
        for(int i = curIdx; i < candidates.size(); i++) {
            if(i != curIdx && candidates[i] == candidates[i - 1])
                continue;
            curr.push_back(candidates[i]);
            findSubsequences(combns, curr, candidates, sum + candidates[i], target, i + 1);
            curr.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> v;
        vector<vector<int>> combns;
        sort(candidates.begin(), candidates.end());
        findSubsequences(combns, v, candidates, 0, target, 0);
        return combns;
    }
};
