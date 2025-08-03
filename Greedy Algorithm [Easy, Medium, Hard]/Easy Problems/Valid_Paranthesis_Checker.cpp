// https://leetcode.com/problems/valid-parenthesis-string/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        int low = 0; // minimum number of unmatched open parentheses possible
        int high = 0; // maximum number of unmatched open parentheses possible
        for(char c : s) {
            if(c == '(') {
                low++;
                high++;
            } 
            else if(c == ')') {
                if(low > 0) 
                    low--;
                high--;
                if(high < 0) 
                    return false;
            } else { // c == '*'
                if (low > 0) low--;
                high++;
            }

        }
        return low == 0;
    }
};