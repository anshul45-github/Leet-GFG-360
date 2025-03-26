#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    Node* children[26];
    bool EOW;
    Node() {
        for(int i = 0; i < 26; i++)
            children[i] = nullptr;
        EOW = false;
    }
    void insert(string& str) {
        Node* curr = this;
        for(int i = 0; i < str.size(); i++) {
            int idx = str[i] - 'a';
            if(curr -> children[idx] == nullptr)
                curr -> children[idx] = new Node();
            curr = curr -> children[idx];
        }
        curr -> EOW = true;
    }
    bool search(string& str) {
        Node* curr = this;
        for(int i = 0; i < str.size(); i++) {
            if(str[i] == '.') {
                for(int j = 0; j < 26; j++) {
                    if(curr -> children[j]) {
                        Node* n = curr -> children[j];
                        string newS = str.substr(i + 1);
                        if(n -> search(newS))
                            return true;
                    }
                }
                return false;
            }
            int idx = str[i] - 'a';
            if(curr -> children[idx] == nullptr)
                return false;
            curr = curr -> children[idx];
        }
        return curr -> EOW;
    }
};

class WordDictionary {
public:
    Node* root;
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        root -> insert(word);
    }
    
    bool search(string word) {
        return root -> search(word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */