#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<string>> solutions;

    bool isSafe(vector<string>& board, int row, int col) {
        int n = board.size();

        for(int i = 0; i < n; i++) {
            if(board[i][col] == 'Q')
                return false;
        }

        int i = row + 1;
        int j = col + 1;

        while(i < n && j < n) {
            if(board[i][j] == 'Q')
                return false;
            i++;
            j++;
        }

        i = row + 1;
        j = col - 1;

        while(i < n && j >= 0) {
            if(board[i][j] == 'Q')
                return false;
            i++;
            j--;
        }

        i = row - 1;
        j = col + 1;

        while(i >= 0 && j < n) {
            if(board[i][j] == 'Q')
                return false;
            i--;
            j++;
        }

        i = row - 1;
        j = col - 1;

        while(i >= 0 && j >= 0) {
            if(board[i][j] == 'Q')
                return false;
            i--;
            j--;
        }

        return true;
    }

    void solve(vector<string>& board, int n, int row) {
        if(row == n) {
            solutions.push_back(board);
        }
        for(int i = 0; i < n; i++) {
            if(isSafe(board, row, i)) {
                board[row][i] = 'Q';
                solve(board, n, row + 1);
                board[row][i] = '.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        string str = "";
        for(int i = 0; i < n; i++)
            str += ".";
        vector<string> board(n, str);
        solve(board, n, 0);
        return solutions;
    }
};
