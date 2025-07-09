// https://leetcode.com/problems/repeated-dna-sequences/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> mp;
        vector<string> ans;
        for(int i = 0; i <= (int)s.size() - 10; i++) {
            string temp = s.substr(i, 10);
            if(mp[temp]++ == 1)
                ans.push_back(temp);
        }
        return ans;
    }
};