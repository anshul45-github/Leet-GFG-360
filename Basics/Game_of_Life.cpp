// https://leetcode.com/problems/game-of-life/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> dirs = {{1, 1}, {1, 0}, {0, 1}, {0, -1}, {-1, 0}, {-1, -1}, {1, -1}, {-1, 1}};
    int update(vector<vector<int>>& board, int i, int j) {
        int l = 0;
        for(auto& d : dirs) {
            int ni = i + d[0];
            int nj = j + d[1];
            if(ni >= 0 && ni < board.size() && nj >= 0 && nj < board[ni].size() && board[ni][nj] % 2 == 1)
                l++;
        } 
        if(board[i][j] == 0 && l == 3)
            return 2;
        if(board[i][j] == 1) {
            if(l < 2 || l > 3)
                return 3;
            return 1;
        }
        return 0;
    }
public:
    void gameOfLife(vector<vector<int>>& board) {
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[i].size(); j++) 
                board[i][j] = update(board, i, j);
        }
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[i].size(); j++) {
                if(board[i][j] == 2)
                    board[i][j] = 1;
                else if(board[i][j] == 3)
                    board[i][j] = 0;
            }
        }
    }
};