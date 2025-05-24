// https://leetcode.com/problems/group-anagrams/
// Medium

// Given an array of strings strs, group the anagrams together. You can return the answer in any order.

// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

// Example 1:
// Input: strs = ["eat","tea","tan","ate","nat","bat"]
// Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
// Explanation: One possible answer is [["bat"],["nat","tan"],["ate","eat","tea"]], where each group of anagrams is sorted in lexicographical order.

// Example 2:
// Input: strs = [""]
// Output: [[""]]

// Example 3:
// Input: strs = ["a"]
// Output: [["a"]]

// Constraints:
// 1 <= strs.length <= 10^4
// 0 <= strs[i].length <= 100
// strs[i] consists of lowercase English letters.

#include<vector>
#include<unordered_map>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, int> mp;
        int idx = 0;
        vector<vector<string>> ans;
        for(int i = 0; i < strs.size(); i++) {
            string x = strs[i];
            sort(x.begin(), x.end());
            if(!mp.count(x)) {
                mp[x] = idx;
                idx++;
                vector<string> temp = {strs[i]};
                ans.push_back(temp);
            }
            else 
                ans[mp[x]].push_back(strs[i]);
        }
        return ans;
    }
};