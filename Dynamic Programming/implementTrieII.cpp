#include<bits/stdc++.h>
using namespace std;

class Trie{
    int EOW;
    int count;
    Trie* children[26];
    
public:
    Trie() {
        for(int i = 0; i < 26; i++)
            children[i] = nullptr;
        EOW = 0;
        count = 0;
    }

    void insert(string &word) {
        Trie* t = this;
        for(int i = 0; i < word.size(); i++) {
            int idx = word[i] - 'a';
            if(t -> children[idx] == nullptr)
                t -> children[idx] = new Trie();
            t = t -> children[idx];
            t -> count += 1;
        }
        t -> EOW += 1;
    }

    int countWordsEqualTo(string &word) {
        Trie* t = this;
        for(int i = 0; i < word.size(); i++) {
            int idx = word[i] - 'a';
            if(t -> children[idx] == nullptr)
                return 0;
            t = t -> children[idx];
        }
        return t -> EOW;
    }

    int countWordsStartingWith(string &word) {
        Trie* t = this;
        for(int i = 0; i < word.size(); i++) {
            int idx = word[i] - 'a';
            if(t -> children[idx] == nullptr)
                return 0;
            t = t -> children[idx];
        }
        return t -> count;
    }

    void erase(string &word) {
        Trie* t = this;
        for(int i = 0; i < word.size(); i++) {
            int idx = word[i] - 'a';
            t = t -> children[idx];
            t -> count -= 1;
        }
        t -> EOW -= 1;
    }
};
