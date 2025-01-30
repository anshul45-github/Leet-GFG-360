#include<bits/stdc++.h>
using namespace std;

class Trie {
public:
    Trie* children[26];
    Trie() {
        for(int i = 0; i < 26; i++)
            children[i] = nullptr;
    }
};

int countDistinctSubstrings(string &s) {
    Trie* t = new Trie();
    int cnt = 1;
    for(int i = 0; i < s.size(); i++) {
        Trie* temp = t;
        for(int j = i; j < s.size(); j++) {
            int idx = s[j] - 'a';
            if(temp -> children[idx] == nullptr) {
                cnt++;
                temp -> children[idx] = new Trie();
            }
            temp = temp -> children[idx];
        }
    }
    return cnt;
}
