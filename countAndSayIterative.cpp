#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string* s = new string[n];
        s[0] = "1";
        for(int i = 1; i < n; i++) {
            string a = "";
            for(int j = 0; j < s[i - 1].size();) {
                char ch = s[i - 1][j];
                int count = 0;
                while(j < s[i - 1].size() && s[i - 1][j] == ch) {
                    j++;
                    count++;
                }
                a = a + to_string(count) + ch;
            }
            s[i] = a;
        }
        return s[n - 1];
    }
};
