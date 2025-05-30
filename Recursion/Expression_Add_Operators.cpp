// https://leetcode.com/problems/expression-add-operators/
// 282. Expression Add Operators
// Hard

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> ans;
    string s;
    int target;
    vector<string> addOperators(string s, int target) {
        this->s = s;
        this->target = target;
        backtrack( 0, "", 0, 0);
        return ans;
    }
    void backtrack(int i, const string& path, long resSoFar, long prevNum) {
        if (i == s.length()) {
            if (resSoFar == target) ans.push_back(path);
            return;
        }
        string numStr;
        long num = 0;
        for (int j = i; j < s.length(); j++) {
            if (j > i && s[i] == '0') break;
            numStr += s[j];
            num = num * 10 + s[j] - '0';
            if (i == 0) {
                backtrack(j + 1, path + numStr, num, num);
            } else {
                backtrack(j + 1, path + "+" + numStr, resSoFar + num, num);
                backtrack(j + 1, path + "-" + numStr, resSoFar - num, -num);
                backtrack(j + 1, path + "*" + numStr, resSoFar - prevNum + prevNum * num, prevNum * num);
            }
        }
    }
};
