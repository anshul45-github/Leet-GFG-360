// https://leetcode.com/problems/valid-palindrome/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        for(int i = 0; i < s.size(); i++) {
            if(s[i] >= 'a' && s[i] <= 'z')
                continue;
            if(s[i] >= 'A' && s[i] <= 'Z')
                s[i] = (char)((s[i] - 'A') + 'a');
        }
        for(int i = 0, j = s.size() - 1; i <= j; i++, j--) {
            while(i <= j && (s[i] < 'a' || s[i] > 'z') && (s[i] < '0' || s[i] > '9'))
                i++;
            while(i <= j && (s[j] < 'a' || s[j] > 'z') && (s[j] < '0' || s[j] > '9'))
                j--;
            if(i <= j && s[i] != s[j]) {
                return false;
            }
        }
        return true;
    }
};
