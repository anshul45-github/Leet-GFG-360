// https://leetcode.com/problems/longest-absolute-file-path/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthLongestPath(string input) {
        vector<int> lens;
        int lvl = 0;
        int ans = 0;
        for(int i = 0; i < input.size();) {
            int len = 0;
            bool isFile = false;
            while(i < input.size() && input[i] != '\n') {
                if(input[i] == '.')
                    isFile = true;
                i++;
                len++;
            }
            if(lvl < lens.size())
                lens[lvl] = len;
            else
                lens.push_back(len);
            if(isFile)
                ans = max(ans, accumulate(lens.begin(), lens.begin() + lvl + 1, 0) + lvl);
            i++;
            lvl = 0;
            while(i < input.size() && input[i] == '\t') {
                i++;
                lvl++;
            }
        }
        return ans;
    }
};