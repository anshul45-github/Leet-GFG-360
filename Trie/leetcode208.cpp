#include<bits/stdc++.h>
using namespace std;

class Trie {
    Trie* children[26];
    bool EOW;
public:
    Trie() {
        for(int i = 0; i < 26; i++)
            children[i] = nullptr;
        EOW = false;
    }
    
    void insert(string word) {
        Trie* t = this;
        for(int i = 0; i < word.size(); i++) {
            int idx = word[i] - 'a';
            if(t -> children[idx] == nullptr)
                t -> children[idx] = new Trie();
            t = t -> children[idx];
        }
        t -> EOW = true;
        return;
    }
    
    bool search(string word) {
        Trie* t = this;
        for(int i = 0; i < word.size(); i++) {
            int idx = word[i] - 'a';
            if(t -> children[idx] == nullptr)
                return false;
            t = t -> children[idx];
        }
        return t -> EOW;
    }
    
    bool startsWith(string prefix) {
        Trie* t = this;
        for(int i = 0; i < prefix.size(); i++) {
            int idx = prefix[i] - 'a';
            if(t -> children[idx] == nullptr)
                return false;
            t = t -> children[idx];
        }
        return true;
    }
};
