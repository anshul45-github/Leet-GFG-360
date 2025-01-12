// SC : O(N) where N is the total no of rows in the triangle
#include<bits/stdc++.h>
using namespace std;

class Solution {
    int solveTab(vector<vector<int>>& triangle) {
        vector<int> next(triangle[triangle.size() - 1].size() + 1, 0);
        vector<int> curr(triangle[triangle.size() - 1].size() + 1, 1e9);
        for(int i = triangle.size() - 1; i >= 0; i--) {
            for(int col = triangle[i].size() - 1; col >= 0; col--) {
                curr[col] = min(next[col], next[col + 1]) + triangle[i][col];
            }
            next = curr;
        }
        return next[0];
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        return solveTab(triangle);
    }
};
