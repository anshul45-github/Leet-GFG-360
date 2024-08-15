#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if(n == 1)
            return "1";
        string s = countAndSay(n - 1);
        string a = "";
        for(int i = 0; i < s.size();) {
            char ch = s[i];
            int count = 0;
            while(i < s.size() && s[i] == ch) {
                i++;
                count++;
            }
            a = a + to_string(count) + ch;
        }
        return a;
    }
};
