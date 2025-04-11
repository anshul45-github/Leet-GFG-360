// Problem Name - Partition Labels
// Sheet - Neetcode 150
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> start(26, -1);
        vector<int> end(26, -1);
        for(int i = 0; i < s.size(); i++) {
            int idx = s[i] - 'a';
            if(start[idx] == -1) {
                start[idx] = i;
                end[idx] = i;
            }
            else
                end[idx] = i;
        }
        vector<int> sizes;
        int startIdx = 0;
        int endIdx = 0;
        for(int i = 0; i < s.size(); i++) {
            int idx = s[i] - 'a';
            int End = end[idx];
            endIdx = max(End, endIdx);
            if(endIdx == i) {
                sizes.push_back(endIdx - startIdx + 1);
                startIdx = endIdx + 1;
                endIdx = startIdx;
            }
        }
        return sizes;
    }
};
