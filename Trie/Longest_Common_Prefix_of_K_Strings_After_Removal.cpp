// https://leetcode.com/problems/longest-common-prefix-of-k-strings-after-removal/
// 3485. Longest Common Prefix of K Strings After Removal
// Hard

#include<string>
#include<vector>
using namespace std;

class Node {
public:
    Node* children[26];
    int words;
    int bestPrefix;
    Node() {
        for(int i = 0; i < 26; i++)
            children[i] = nullptr;
        words = 1;
        bestPrefix = 0;
    }
};

class Solution {
    void insert(Node* root, string& s, int k) {
        vector<int> depth(s.size() + 1, 0);
        vector<Node*> nodes(s.size() + 1, nullptr);
        nodes[0] = root;
        depth[0] = 0;
        for(int i = 0; i < s.size(); i++) {
            int idx = s[i] - 'a';
            if(root -> children[idx])
                root -> children[idx] -> words++;
            else
                root -> children[idx] = new Node();
            nodes[i + 1] = nodes[i] -> children[idx];
            root = root -> children[idx];
            depth[i + 1] = depth[i] + 1;
        }
        for(int i = s.size(); i >= 0; i--) {
            int maxi = (nodes[i] -> words >= k ? depth[i] : 0);
            for(int j = 0; j < 26; j++) {
                if(nodes[i] -> children[j] != nullptr)
                    maxi = max(maxi, nodes[i] -> children[j] -> bestPrefix);
            }
            nodes[i] -> bestPrefix = maxi;
        }
    }
    void remove(Node* root, string& s, int k) {
        vector<int> depth(s.size() + 1, 0);
        vector<Node*> nodes(s.size() + 1, nullptr);
        nodes[0] = root;
        depth[0] = 0;
        for(int i = 0; i < s.size(); i++) {
            int idx = s[i] - 'a';
            root -> children[idx] -> words--;
            nodes[i + 1] = nodes[i] -> children[idx];
            root = root -> children[idx];
            depth[i + 1] = depth[i] + 1;
        }
        for(int i = s.size(); i >= 0; i--) {
            int maxi = (nodes[i] -> words >= k ? depth[i] : 0);
            for(int j = 0; j < 26; j++) {
                if(nodes[i] -> children[j] != nullptr)
                    maxi = max(maxi, nodes[i] -> children[j] -> bestPrefix);
            }
            nodes[i] -> bestPrefix = maxi;
        }
    }
public:
    vector<int> longestCommonPrefix(vector<string>& words, int k) {
        vector<int> ans(words.size(), 0);
        if(words.size() - 1 < k)
            return ans;
        Node* root = new Node();
        for(string& word : words)
            insert(root, word, k);
        for(int i = 0; i < words.size(); i++) {
            remove(root, words[i], k);
            ans[i] = root -> bestPrefix;
            insert(root, words[i], k);
        }
        return ans;
    }
};