// https://leetcode.com/problems/cracking-the-safe/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string dfs(int n, int k, string& soFar, unordered_set<string>& generated, int targetLen) {
        string newPass = soFar.length() >= n ? soFar.substr(soFar.length() - n, n) : "";
        if(newPass.length()) {
            if(generated.find(newPass) != generated.end()) 
                return "";
            generated.insert(newPass);
        }
        if(soFar.length() == targetLen) 
            return soFar;
        for(int i = 0; i < k; i++) {
            soFar.push_back(i + '0');
            string res = dfs(n, k, soFar, generated, targetLen);
            if(res != "") 
                return res;
            soFar.pop_back();
        }
        if(newPass.length()) 
            generated.erase(newPass);
        return "";
    }
    string crackSafe(int n, int k) {
        unordered_set<string> generated;
        string soFar = "";
        return dfs(n, k, soFar, generated, pow(k, n) + (n - 1));
    }
};