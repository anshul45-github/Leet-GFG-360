#include<bits/stdc++.h>
using namespace std;

class Solution {
    string expand(string str, int i, int j) {
        while(i >= 0 && j < str.size() && str[i] == str[j]) {
            i--;
            j++;
        }
        return str.substr(i + 1, j - i - 1);
    }
public:
    string longestPalindrome(string s) {
        string ans = s.substr(0, 1);
        for(int i = 0; i < s.size(); i++) {
            string odd_str = expand(s, i, i);
            string even_str = expand(s, i, i + 1);
            if(odd_str.size() > ans.size())
                ans = odd_str;
            if(even_str.size() > ans.size())
                ans = even_str;
        }
        return ans;
    }
};
