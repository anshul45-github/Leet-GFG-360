#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool isSafe(vector<vector<char>>& board, char num, int row, int col) {
        for(int i = 0; i < 9; i++) {
            if(board[i][col] == num || board[row][i] == num)
                return false;
        }

        int boxRow = (row / 3) * 3;
        int boxCol = (col / 3) * 3;

        for(int i = boxRow; i < boxRow + 3; i++) {
            for(int j = boxCol; j < boxCol + 3; j++) {
                if(board[i][j] == num)
                    return false;
            }
        }

        return true;
    }

    bool solve(vector<vector<char>>& board, int i, int j) {
        if(i == 9)
            return true;

        if(j == 9)
            return solve(board, i + 1, 0);

        if(board[i][j] != '.')
            return solve(board, i, j + 1);

        for(char num = '1'; num <= '9'; num++) {
            if(isSafe(board, num, i, j)) {
                board[i][j] = num;
                if(solve(board, i, j + 1))
                    return true;
                board[i][j] = '.';
            }
        }

        return false;
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board, 0, 0);
    }
};
