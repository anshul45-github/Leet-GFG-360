// https://leetcode.com/problems/palindrome-number/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        string str = to_string(x);
        for(int i = 0, j = str.size() - 1; i < j; i++, j--) {
            if(str[i] != str[j])
                return false;
        }
        return true;
    }

    bool isPalindromeWithoutConvertingIntToStr(int x) {
        if(x < 0)
            return false;
        vector<int> digits;
        while(x > 0) {
            digits.push_back(x % 10);
            x /= 10;
        }
        for(int i = 0, j = digits.size() - 1; i < j; i++, j--) {
            if(digits[i] != digits[j])
                return false;
        }
        return true;
    }
};
