// https://leetcode.com/problems/expression-add-operators/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<string> ans;
    void solve(string& num, int target, string currPath, long long resSoFar, long long prevNum, int i) {
        if(i == num.size()) {
            if(resSoFar == target)
                ans.push_back(currPath);
            return;
        }
        long long currNum = 0;
        for(int idx = i; idx < num.size(); idx++) {
            if(idx > i && num[i] == '0')
                break;
            currNum = currNum * 10 + (num[idx] - '0');
            if(i == 0) 
                solve(num, target, to_string(currNum), currNum, currNum, idx + 1);
            else {
                solve(num, target, currPath + "+" + to_string(currNum), resSoFar + currNum, currNum, idx + 1);
                solve(num, target, currPath + "-" + to_string(currNum), resSoFar - currNum, -currNum, idx + 1);
                solve(num, target, currPath + "*" + to_string(currNum), resSoFar - prevNum + currNum * prevNum, currNum * prevNum, idx + 1);
            }
        }
    }
public:
    vector<string> addOperators(string num, int target) {
        solve(num, target, "", 0, 0, 0);
        return ans;
    }
};