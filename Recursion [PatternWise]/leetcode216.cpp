#include<bits/stdc++.h>
using namespace std;

class Solution {
    void combns(int i, int k, int n, int noTaken, int sum, vector<int> combination, vector<vector<int>>& v) {
        if(noTaken == k && sum == n) {
            v.push_back(combination);
            return;
        }
        if(sum > n || noTaken == k || i == 10)
            return;
        combination.push_back(i);
        combns(i + 1, k, n, noTaken + 1, sum + i, combination, v);
        combination.pop_back();
        combns(i + 1, k, n, noTaken, sum, combination, v);
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> combination;
        vector<vector<int>> v;
        combns(1, k, n, 0, 0, combination, v);
        return v;
    }
};
