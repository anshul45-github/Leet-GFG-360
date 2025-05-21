// https://leetcode.com/problems/set-matrix-zeroes/
// 73. Set Matrix Zeroes
// Medium

#include<bits/stdc++.h>
using namespace std;

class Solution {
    void setRowZero(vector<vector<int>>& matrix, int i) {
        for(int j = 0; j < matrix[0].size(); j++)
            matrix[i][j] = 0;
    }
    void setColZero(vector<vector<int>>& matrix, int j) {
        for(int i = 0; i < matrix.size(); i++) 
            matrix[i][j] = 0;
    }
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool firstRow = false;
        bool firstCol = false;
        for(int i = 0; i < matrix.size(); i++) {
            if(matrix[i][0] == 0) {
                firstCol = true;
                break;
            }
        }
        for(int i = 0; i < matrix[0].size(); i++) {
            if(matrix[0][i] == 0) {
                firstRow = true;
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
            if(matrix[i][0] == 0) 
                setRowZero(matrix, i);
        }
        for(int j = 1; j < matrix[0].size(); j++) {
            if(matrix[0][j] == 0)
                setColZero(matrix, j);
        }
        if(firstRow)
            setRowZero(matrix, 0);
        if(firstCol)
            setColZero(matrix, 0);
    }
};