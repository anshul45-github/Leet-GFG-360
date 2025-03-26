#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    Node* children[26];
    bool eow;
    string word;
    Node() {
        for(int i = 0; i < 26; i++)
            children[i] = nullptr;
        eow = false;
        word = "";
    }
};

class Trie {
public:
    Node* root;
    Trie() {
        root = new Node();
    }
    void insert(string& s) {
        Node* curr = root;
        for(int i = 0; i < s.size(); i++) {
            int idx = s[i] - 'a';
            if(curr -> children[idx] == nullptr)
                curr -> children[idx] = new Node();
            curr = curr -> children[idx];
        }
        curr -> eow = true;
        curr -> word = s;
    }
    int x[4] = {1, -1, 0, 0};
    int y[4] = {0, 0, 1, -1};
    void check(vector<vector<char>>& board, int i, int j, int n, int m, Node* curr, vector<string>& ans) {
        if(i < 0 || i >= n || j < 0 || j >= m || board[i][j] == '#' || curr -> children[board[i][j] - 'a'] == nullptr)
            return;
        curr = curr -> children[board[i][j] - 'a'];
        if(curr -> eow) {
            ans.push_back(curr -> word);
            curr -> eow = false;
            // return;
        }
        char temp = board[i][j];
        board[i][j] = '#';
        for(int k = 0; k < 4; k++) {
            int nx = i + x[k];
            int ny = j + y[k];
            check(board, nx, ny, n, m, curr, ans);
        }
        board[i][j] = temp;
    }
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int n = board.size();
        int m = board[0].size();
        Trie* t = new Trie();
        for(int i = 0; i < words.size(); i++)
            t -> insert(words[i]);
        vector<string> ans;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++)
                t -> check(board, i, j, n, m, t -> root, ans);
        }
        return ans;
    }
};