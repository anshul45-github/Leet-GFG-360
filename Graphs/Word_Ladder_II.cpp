// https://leetcode.com/problems/word-ladder-ii/
// Hard

// Given two words (beginWord and endWord), and a dictionary's word list, find all shortest transformation sequence(s) from beginWord to endWord, such that:
// Only one letter can be changed at a time.

// Note:
// Return an empty list if there is no such transformation sequence.
// All words have the same length.
// All words contain only lowercase alphabetic characters.
// You may assume no duplicates in the word list.
// You may assume beginWord and endWord are non-empty and are not the same.

// Example 1:
// Input:
// beginWord = "hit",
// endWord = "cog",
// wordList = ["hot","dot","dog","lot","log","cog"]
// Output: [
// ["hit","hot","dot","dog","cog"],
// ["hit","hot","lot","log","cog"]
// ]

// Example 2:
// Input:
// beginWord = "hit"
// endWord = "cog"
// wordList = ["hot","dot","dog","lot","log"]
// Output: []
// Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.

#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
    vector<vector<string>> ans;
    void backtracking(unordered_map<string, vector<string>>& parent, string& curr, string& dest, vector<string>& path) {
        if(curr == dest) {
            vector<string> tmp = path;
            reverse(tmp.begin(), tmp.end());
            ans.push_back(tmp);
            return;
        }
        for(auto& str : parent[curr]) {
            path.push_back(str);
            backtracking(parent, str, dest, path);
            path.pop_back();
        }
    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        queue<string> q;
        unordered_map<string, vector<string>> parent;
        unordered_set<string> s(wordList.begin(), wordList.end());
        unordered_set<string> visited;
        q.push(beginWord);
        q.push("");
        int lvl = 1;
        bool done = false;
        while(!q.empty()) {
            string curr = q.front();
            q.pop();
            if(curr == "") {
                for(auto& w : visited)
                    s.erase(w);
                visited.clear();
                if(q.empty() || done)
                    break;
                q.push("");
                lvl++;
            }
            else if(curr == endWord)
                done = true;
            string tmp = curr;
            for(int i = 0; i < curr.size(); i++) {
                char original = curr[i];
                for(char ch = 'a'; ch <= 'z'; ch++) {
                    if(ch == original)
                        continue;
                    curr[i] = ch;
                    if(s.find(curr) != s.end()) {
                        if(!parent.count(curr))
                            q.push(curr);
                        parent[curr].push_back(tmp);
                        visited.insert(curr);
                    }
                }
                curr[i] = original;
            }
        }
        if(!done)
            return ans;
        vector<string> path = {endWord};
        backtracking(parent, endWord, beginWord, path);
        return ans;
    }
};