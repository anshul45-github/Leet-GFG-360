// https://leetcode.com/problems/reverse-integer/
// 7. Reverse Integer
// Medium

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        // int noOfDigits = 0;
        int reversedNum = 0;
        while(x != 0) {
            if(x > 0) {
                if(reversedNum > (INT_MAX - x) / 10)
                    return 0;
            }
            else if(x < 0) {
                if(reversedNum < (INT_MIN - x) / 10)
                    return 0;
            }
            reversedNum *= 10;
            reversedNum += x % 10;
            x = x/10;
            // noOfDigits++;
        }
        return reversedNum;
    }
};
