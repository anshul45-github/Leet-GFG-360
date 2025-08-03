#include<bits/stdc++.h>
using namespace std;

class Solution {
    void dfs(vector<vector<char>>& board, pair<int, int> curr) {
        if(curr.first < 0 || curr.second < 0 || curr.first >= board.size() || curr.second >= board[0].size() || board[curr.first][curr.second] != 'O')
            return;
        board[curr.first][curr.second] = '#';
        dfs(board, {curr.first + 1, curr.second});
        dfs(board, {curr.first - 1, curr.second});
        dfs(board, {curr.first, curr.second + 1});
        dfs(board, {curr.first, curr.second - 1});
    }
public:
    void solve(vector<vector<char>>& board) {
        for(int i = 0; i < board.size(); i++) {
            if(board[i][0] == 'O')
                dfs(board, {i, 0});
            if(board[i][board[0].size() - 1] == 'O')
                dfs(board, {i, board[0].size() - 1});
        }
        for(int i = 0; i < board[0].size(); i++) {
            if(board[0][i] == 'O')
                dfs(board, {0, i});
            if(board[board.size() - 1][i] == 'O')
                dfs(board, {board.size() - 1, i});
        }
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                if(board[i][j] == 'O')
                    board[i][j] = 'X';
                if(board[i][j] == '#')
                    board[i][j] = 'O';
            }
        }
        return;
    }
};
