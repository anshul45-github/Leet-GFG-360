// https://leetcode.com/problems/letter-combinations-of-a-phone-number/

#include<bits/stdc++.h>
using namespace std;

unordered_map<int, string> mp = {{2, "abc"}, {3, "def"}, {4, "ghi"}, {5, "jkl"}, {6, "mno"}, {7, "pqrs"}, {8, "tuv"}, {9, "wxyz"}};

class Solution {
    void helper(vector<string>& combns, string digits, int idx, string comb) {
        if(idx == digits.size()) {
            if(comb != "")
                combns.push_back(comb);
            return;
        }
        int curr = digits[idx] - '0';
        for(int i = 0; i < mp[curr].size(); i++) {
            helper(combns, digits, idx + 1, comb + mp[curr][i]);
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> v;
        helper(v, digits, 0, "");
        return v;
    }
};
