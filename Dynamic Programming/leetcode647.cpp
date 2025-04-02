#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        vector<vector<bool>> isPalindrome(s.size(), vector<bool>(s.size(), false));
        int ans = 0;
        for(int i = 0; i < s.size(); i++) {
            isPalindrome[i][i] = true;
            ans++;
        }
        for(int i = 0; i < s.size() - 1; i++) {
            if(s[i] == s[i + 1]) {
                isPalindrome[i][i + 1] = true;
                ans++;
            }
        }
        for(int len = 3; len <= s.size(); len++) {
            for(int i = 0; i < s.size() - len + 1; i++) {
                if(s[i] == s[i + len - 1] && isPalindrome[i + 1][i + len - 2]) {
                    isPalindrome[i][i + len - 1] = true;
                    ans++;
                }
            }
        }
        return ans;
    }
};
