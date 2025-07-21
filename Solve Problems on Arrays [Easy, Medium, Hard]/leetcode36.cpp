#include<bits/stdc++.h>
using namespace std;

// CHECK EACH ROW
// CHECK EACH COL
// CHECK EACH 3X3 GRID
// IF ANY OF THE ABOVE FAILS, RETURN FALSE
// ELSE RETURN TRUE

// TIME COMPLEXITY: O(1)
// SPACE COMPLEXITY: O(1)

class Solution {
    bool isValidRow(vector<char>& b) {
        vector<bool> vis(9, false);
        for(int i = 0; i < 9; i++) {
            if(b[i] == '.')
                continue;
            if(vis[b[i] - '1']) {
                return false;
            }
            vis[b[i] - '1'] = true;
        }
        return true;
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++) {
            if(!isValidRow(board[i]))
                return false;
        }
        for(int j = 0; j < 9; j++) {
            vector<bool> vis(9, false);
            for(int i = 0; i < 9; i++) {
                if(board[i][j] == '.')
                    continue;
                if(vis[board[i][j] - '1']) {
                    return false;
                }
                vis[board[i][j] - '1'] = true;
            }
        }
        for(int i = 0; i < 9; i++) {
            int j = i / 3;
            int k = i % 3;
            j *= 3;
            k *= 3;
            int n = 0;
            vector<bool> vis(9, false);
            for(; n < 3; j++, n++) {
                int m = 0;
                for(; m < 3; k++, m++) {
                    if(board[j][k] == '.')
                        continue;
                    if(vis[board[j][k] - '1']) {
                        return false;
                    }
                    vis[board[j][k] - '1'] = true;
                }
                k -= 3;
            }
        }
        return true;
    }
};