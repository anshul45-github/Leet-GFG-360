// https://leetcode.com/problems/set-matrix-zeroes/

#include<bits/stdc++.h>
using namespace std;

// Approach 1 - Using Extra Space
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> visited = matrix;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(matrix[i][j] == 0) {
                    for(int k = 0; k < m; k++) 
                        visited[i][k] = 0;
                    for(int k = 0; k < n; k++)
                        visited[k][j] = 0;
                }
            }
        }
        matrix = visited;
    }
};

// Approach 2 - Using Constant Space (Optimized)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(matrix[i][j] == 0) {
                    for(int k = 0; k < m; k++) {
                        if(matrix[i][k] != 0) 
                            matrix[i][k] = -2025;
                    }
                    for(int k = 0; k < n; k++) {
                        if(matrix[k][j] != 0) 
                            matrix[k][j] = -2025;
                    }
                }
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(matrix[i][j] == -2025)
                    matrix[i][j] = 0;
            }
        }
    }
};

// Approach 3 - Using Hashing
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        unordered_set<int> setRows; 
        unordered_set<int> setColumns; 
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(matrix[i][j] == 0) {
                    setRows.insert(i);
                    setColumns.insert(j);
                }
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(setRows.count(i) || setColumns.count(j)) 
                    matrix[i][j] = 0;
            }
        }
    }
};

// Approach 4 - Using Constant Space (Optimized)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool firstRow = 0;
        bool firstCol = 0;
        for(int i = 0; i < matrix.size(); i++) {
            if(matrix[i][0] == 0) {
                firstCol = 1;
                break;
            }
        }
        for(int i = 0; i < matrix[0].size(); i++) {
            if(matrix[0][i] == 0) {
                firstRow = 1;
                break;
            }
        }
        for(int i = 1; i < matrix.size(); i++) {
            for(int j = 1; j < matrix[0].size(); j++) {
                if(matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        for(int i = 1; i < matrix.size(); i++) {
            if(matrix[i][0] == 0) {
                for(int j = 1; j < matrix[i].size(); j++)
                    matrix[i][j] = 0;
            }
        }
        for(int i = 1; i < matrix[0].size(); i++) {
            if(matrix[0][i] == 0) {
                for(int j = 1; j < matrix.size(); j++)
                    matrix[j][i] = 0;
            }
        }
        if(firstRow) {
            for(int i = 0; i < matrix[0].size(); i++)
                matrix[0][i] = 0;
        }
        if(firstCol) {
            for(int i = 0; i < matrix.size(); i++)
                matrix[i][0] = 0;
        }
    }
};