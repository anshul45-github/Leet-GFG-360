#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int j = 0;
        while(true) {
            if(j == strs[0].size())
                break;
            char ch = strs[0][j];
            bool br = false;
            for(int i = 1; i < strs.size(); i++) {
                if(j == strs[i].size() || strs[i][j] != ch) {
                    br = true;
                    break;
                }
            }
            if(br)
                break;
            j++;
        }
        return strs[0].substr(0, j);
    }
};
