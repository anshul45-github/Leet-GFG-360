#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> tri(numRows);
        tri[0] = {1};
        for(int i = 1; i < numRows; i++) {
            tri[i].push_back(1);
            for(int j = 1; j < i; j++) {
                int a = tri[i - 1][j - 1] + tri[i - 1][j];
                tri[i].push_back(a);
            }
            tri[i].push_back(1);
        }
        return tri;
    }
};
