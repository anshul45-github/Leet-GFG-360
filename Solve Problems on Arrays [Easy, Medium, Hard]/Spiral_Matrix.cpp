// https://leetcode.com/problems/spiral-matrix/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rowStart = 0, rowEnd = matrix.size() - 1;
        int colStart = 0, colEnd = matrix[0].size() - 1;
        vector<int> ans;
        while(rowStart <= rowEnd && colStart <= colEnd) {
            for(int i = colStart; i <= colEnd; i++)
                ans.push_back(matrix[rowStart][i]);
            for(int i = rowStart + 1; i < rowEnd; i++)
                ans.push_back(matrix[i][colEnd]);
            if(rowStart != rowEnd) {
                for(int i = colEnd; i >= colStart; i--)
                    ans.push_back(matrix[rowEnd][i]);
            }
            if(colStart != colEnd) {
                for(int i = rowEnd - 1; i > rowStart; i--)
                    ans.push_back(matrix[i][colStart]);
            }
            rowStart++;
            rowEnd--;
            colStart++;
            colEnd--;
        }
        return ans;
    }
};