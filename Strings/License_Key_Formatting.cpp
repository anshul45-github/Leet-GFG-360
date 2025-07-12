// https://leetcode.com/problems/license-key-formatting/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        int els = 0;
        string ans = "";
        for(int i = s.size() - 1; i >= 0; i--) {
            if(s[i] != '-') {
                if(els % k == 0 && els != 0)
                    ans += '-';
                if(s[i] >= 'a' && s[i] <= 'z')
                    ans += s[i] + 'A' - 'a';
                else
                    ans += s[i];
                els++;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};