// https://www.naukri.com/code360/problems/word-break-ii_983635?leftPanelTabValue=PROBLEM
// Hard

// Given a string s and a dictionary of strings wordDict, add spaces in s to construct a sentence where each word is a valid dictionary word. Return all such possible sentences.

// Note: The same word in the dictionary may be reused multiple times in the segmentation.

// Example 1:
// Input: s = "catsanddog", wordDict = ["cat","cats","and","sand","dog"]
// Output: ["cats and dog","cat sand dog"]

// Example 2:
// Input: s = "pineapplepenapple", wordDict = ["apple","pen","applepen","pine","pineapple"]
// Output: ["pine apple pen apple","pineapple pen apple","pine applepen apple"]

// Example 3:
// Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
// Output: []

// Constraints:
// 1 <= s.length <= 13
// 1 <= wordDict.length <= 100
// 1 <= wordDict[i].length <= 16

// The same word in wordDict may be reused multiple times in the segmentation.

// Approach: Backtracking with Memoization

#include <bits/stdc++.h> 
using namespace std;

void solve(string& s, unordered_set<string>& set, vector<string>& ans, string curr, int idx, unordered_map<int, unordered_map<string, bool>>& mp) {
    if(idx == s.size()) {
        ans.push_back(curr);
        return;
    }
    if(mp[idx][curr])
        return;
    string n = "";
    if(curr != "")
        curr += " ";
    for(int i = idx; i < s.size(); i++) {
        n += s[i];
        if(set.find(n) != set.end())
            solve(s, set, ans, curr + n, i + 1, mp);
    }
    mp[idx][curr] = true;
}

vector<string> wordBreak(string &s, vector<string> &dictionary) {
    unordered_set<string> set(dictionary.begin(), dictionary.end());
    unordered_map<int, unordered_map<string, bool>> mp;
    vector<string> ans;
    solve(s, set, ans, "", 0, mp);
    return ans;
}