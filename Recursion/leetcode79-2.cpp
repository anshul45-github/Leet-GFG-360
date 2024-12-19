// Applied search pruning
#include<bits/stdc++.h>
using namespace std;

class Solution {
    //  OpMap
    // 1 -> left, 2 -> right, 3 -> top, 4 -> bottom

    bool solve(vector<vector<char>>& board, string word, int i, int j, int idx, vector<vector<bool>>& vis) {
        if(idx == word.size()) {
            return true;
        }
        if(i < 0 || i >= board.size() || j < 0 || j >= board[i].size())
            return false;
        if(board[i][j] != word[idx])
            return false;
        if(vis[i][j])
            return false;
        if(!vis[i][j])
            vis[i][j] = true;
        bool ans = solve(board, word, i, j + 1, idx + 1, vis) || solve(board, word, i, j - 1, idx + 1, vis) || solve(board, word, i + 1, j, idx + 1, vis) || solve(board, word, i - 1, j, idx + 1, vis);
        vis[i][j] = false;
        return ans;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(word.size() > board.size() * board[0].size())
            return false;
        
        unordered_map<char, int> charFreq;

        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++)
                charFreq[board[i][j]]++;
        }

        unordered_map<char, int> wordCharsFreq;

        for(int i = 0; i < word.size(); i++)
            wordCharsFreq[word[i]]++;
        
        for(int i = 0; i < word.size(); i++) {
            if(wordCharsFreq[word[i]] > charFreq[word[i]])
                return false;
        }

        vector<vector<bool>> vis(board.size(), vector<bool>(board[0].size(), false));
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                if(solve(board, word, i, j, 0, vis))
                    return true;
            }
        }
        return false;
    }
};
