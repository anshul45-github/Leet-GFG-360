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
public:
    string countAndSay(int n) {
        if(n == 1)
            return "1";
        string t = countAndSay(n - 1);
        string s = rle(t);
        return s;
    }
};
