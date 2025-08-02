// https://leetcode.com/problems/generate-parentheses/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<string> ans;
    void solve(int n, int opened, int closed, string temp) {
        if(opened == n && closed == n) {
            ans.push_back(temp);
            return;
        }
        if(opened > closed)
            solve(n, opened, closed + 1, temp + ')');
        if(opened < n)
            solve(n, opened + 1, closed, temp + '(');
    }
public:
    vector<string> generateParenthesis(int n) {
        solve(n, 0, 0, "");
        return ans;
    }
};