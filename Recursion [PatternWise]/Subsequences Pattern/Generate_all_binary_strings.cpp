// https://www.geeksforgeeks.org/problems/generate-all-binary-strings/1

#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<string> ans;
    void solve(int num, string temp) {
        if(num == 0) {
            ans.push_back(temp);
            return;
        }
        solve(num - 1, temp + '0');
        if(temp.back() != '1')
            solve(num - 1, temp + '1');
    }
  public:
    vector<string> generateBinaryStrings(int num) {
        solve(num, "");
        return ans;
    }
};