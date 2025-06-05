// https://www.geeksforgeeks.org/problems/power-set4302/1
// Medium

// Given a string s, find all possible subsets of the string in lexicographical order.

// The subsets should be sorted in lexicographical order and should not contain duplicate subsets.

// Note: The subsets should not contain the empty string.

// Example 1:
// Input: s = "abc"
// Output: ["a","ab","abc","ac","b","bc","c"]

// Example 2:
// Input: s = "ab"
// Output: ["a","ab","b"]

// Example 3:
// Input: s = "xyz"
// Output: ["x","xy","xyz", "xz","y","yz","z"]

#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    void solve(string& s, vector<string>& ans, int idx, string temp) {
        if(idx == s.size()) {
            if(temp != "")
                ans.push_back(temp);
            return;
        }
        solve(s, ans, idx + 1, temp + s[idx]);
        solve(s, ans, idx + 1, temp);
    }
  public:
    vector<string> AllPossibleStrings(string s) {
        vector<string> ans;
        solve(s, ans, 0, "");
        sort(ans.begin(), ans.end());
        return ans;
    }
};