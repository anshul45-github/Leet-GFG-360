// https://leetcode.com/problems/combination-sum/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    void combinations(vector<vector<int>>& combn, int sum, int i, int target, vector<int>& a, vector<int> curr) {
        if(sum > target || i == a.size())
            return;
        if(sum == target) {
            combn.push_back(curr);
            return;
        }
        curr.push_back(a[i]);
        combinations(combn, sum + a[i], i, target, a, curr);
        curr.pop_back();
        combinations(combn, sum, i + 1, target, a, curr);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> v;
        vector<int> a;
        combinations(v, 0, 0, target, candidates, a);
        return v;
    }
};
