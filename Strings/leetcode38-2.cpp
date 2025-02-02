// Solved it iteratively
#include<bits/stdc++.h>
using namespace std;

class Solution {
    string rle(string& str) {
        int i = 0;
        string newStr = "";
        while(i < str.size()) {
            char ch = str[i];
            int cnt = 0;
            while(i < str.size() && str[i] == ch) {
                cnt++;
                i++;
            }
            newStr += (char)(cnt + '0');
            newStr += ch;
        }
        return newStr;
    }
    string solve(int n) {
        string prev = "1";
        for(int i = 2; i <= n; i++) {
            string curr = rle(prev);
            prev = curr;
        }
        return prev;
    }
public:
    string countAndSay(int n) {
        return solve(n);
    }
};
