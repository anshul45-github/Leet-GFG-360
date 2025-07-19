// https://leetcode.com/problems/reverse-string/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    void helper(vector<char>& s, int left, int right) {
        if(left >= right)
            return;
        swap(s[left], s[right]);
        helper(s, left + 1, right - 1);
    }
public:
    void reverseString(vector<char>& s) {
        helper(s, 0, s.size() - 1);
    }
};