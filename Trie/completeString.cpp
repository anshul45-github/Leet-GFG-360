#include<bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h> 

class Trie {
    Trie* children[26];
    bool EOW;
public:
    Trie() {
        for(int i = 0; i < 26; i++)
            children[i] = nullptr;
        EOW = false;
    }
    void insert(string& word) {
        Trie* t = this;
        for(int i = 0; i < word.size(); i++) {
            int idx = word[i] - 'a';
            if(t -> children[idx] == nullptr)
                t -> children[idx] = new Trie();
            t = t -> children[idx];
        }
        t -> EOW = true;
    }
    string lexSmallest() {
        Trie* t = this;
        string ans = "";
        for(int i = 0; i < 26; i++) {
            Trie* child = t -> children[i];
            string newC = "";
            if(child && child -> EOW)
                newC = (char)('a' + i) + (child -> lexSmallest());
            if(newC.size() > ans.size())
                ans = newC;
        }
        return ans;
    }
};

string completeString(int n, vector<string> &a) {
    Trie* t = new Trie();
    for(int i = 0; i < n; i++)
        t -> insert(a[i]);
    string ans = t -> lexSmallest();
    return ans == "" ? "None" : ans;
}
