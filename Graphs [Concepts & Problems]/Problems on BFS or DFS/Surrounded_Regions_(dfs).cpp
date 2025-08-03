// https://leetcode.com/problems/surrounded-regions/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    void dfs(vector<vector<char>>& board, int i, int j) {
        board[i][j] = 'O';
        // cout << i << " " << j << endl;
        for(auto& direction : directions) {
            int x = i + direction[0];
            int y = j + direction[1];
            if(x >= 0 && x < board.size() && y >= 0 && y < board[0].size() && board[x][y] == '*')
                dfs(board, x, y);
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                if(board[i][j] == 'O')
                    board[i][j] = '*';
            }
        }
        for(int j = 0; j < board[0].size(); j++) {
            if(board[0][j] == '*') 
                dfs(board, 0, j);
            if(board.back()[j] == '*')
                dfs(board, board.size() - 1, j);
        }
        for(int i = 0; i < board.size(); i++) {
            if(board[i][0] == '*')
                dfs(board, i, 0);
            if(board[i].back() == '*')
                dfs(board, i, board[0].size() - 1);
        }
        for(auto& row : board) {
            for(auto& i : row) {
                if(i == '*')
                    i = 'X';
            }
        }
    }
};