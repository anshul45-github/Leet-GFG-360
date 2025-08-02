// https://leetcode.com/problems/palindrome-partitioning/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.size() - 1;
        while(i < j) {
            if(s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    void solve(vector<vector<string>>& v, vector<string> curr, string s, string c, int idx) {
        bool flag = isPalindrome(c);
        if(flag && idx == s.size()) {
            v.push_back(curr);
            return;
        }
        if(!flag || idx == s.size())
            return;
        string newStr = "";
        for(int i = idx; i < s.size(); i++) {
            newStr += s[i];
            curr.push_back(newStr);
            solve(v, curr, s, newStr, i + 1);
            curr.pop_back();
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> v;
        vector<string> curr;
        solve(v, curr, s, "", 0);
        return v;
    }
};
