// https://leetcode.com/problems/reverse-words-in-a-string/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string r = "";
        for(int i = 0; i < s.size();) {
            if(s[i] != ' ') {
                int start = i;
                while(i < s.size() && s[i] != ' ')
                    i++;
                string temp = s.substr(start, i - start);
                reverse(temp.begin(), temp.end());
                if(r != "")
                    r += ' ';
                r += temp;
            }
            i++;
        }
        reverse(r.begin(), r.end());
        return r;
    }
};