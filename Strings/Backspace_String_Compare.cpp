// https://leetcode.com/problems/backspace-string-compare/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i = s.size() - 1;
        int j = t.size() - 1;
        int cnt1 = 0, cnt2 = 0;
        while(i >= 0 && j >= 0) {
            if(s[i] == '#') {
                cnt1++;
                i--;
            }
            else if(t[j] == '#') {
                cnt2++;
                j--;
            }
            else if(cnt1 > 0) { 
                cnt1--;
                i--;
            }
            else if(cnt2 > 0) {
                cnt2--;
                j--;
            }
            else if(s[i] != t[j]) 
                return false;
            else {
                i--;
                j--;
            }
        }
        while(i >= 0) {
            if(s[i] == '#') 
                cnt1++;
            else if(cnt1 > 0)
                cnt1--;
            else
                return false;
            i--;
        }
        while(j >= 0) {
            if(t[j] == '#') 
                cnt2++;
            else if(cnt2 > 0)
                cnt2--;
            else
                return false;
            j--;
        }
        return true;
    }
};