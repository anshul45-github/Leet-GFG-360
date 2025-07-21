// https://leetcode.com/problems/plus-one/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if(digits.back() != 9) {
            digits.back() += 1;
            return digits;
        }
        int i = digits.size() - 1;
        while(i >= 0 && digits[i] == 9)
            digits[i--] = 0;
        if(i == -1)
            digits.insert(digits.begin(), 1);
        else
            digits[i] += 1;
        return digits;
    }
};