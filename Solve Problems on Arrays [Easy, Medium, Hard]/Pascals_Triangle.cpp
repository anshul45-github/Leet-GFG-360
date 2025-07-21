// https://leetcode.com/problems/pascals-triangle/

#include<bits/stdc++.h>
using namespace std;

// Approach 1 - Recursive
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows == 0) 
            return {};
        if(numRows == 1) 
            return {{1}};
        
        vector<vector<int>> prevRows = generate(numRows - 1);
        vector<int> newRow(numRows, 1);
        
        for(int i = 1; i < numRows - 1; i++)
            newRow[i] = prevRows.back()[i - 1] + prevRows.back()[i];
        
        prevRows.push_back(newRow);
        return prevRows;
    }
};

// Approach 2 - Iterative
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);
        ans[0] = {1};
        for(int i = 1; i < numRows; i++) {
            ans[i].resize(i + 1);
            ans[i][0] = 1;
            ans[i][i] = 1;
            for(int j = 1; j < i; j++)
                ans[i][j] = ans[i - 1][j] + ans[i - 1][j - 1];
        }
        return ans;
    }
};