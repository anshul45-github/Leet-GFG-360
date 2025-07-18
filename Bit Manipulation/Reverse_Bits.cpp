// https://leetcode.com/problems/reverse-bits/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int start = 31;
        int end = 0;
        while(start > end) {
            int startBit = ((1 << start) & n) > 0; 
            int endBit = ((1 << end) & n) > 0;
            if(startBit) 
                n = n | (1 << end);
            else
                n = n & ~(1 << end);
            if(endBit)
                n = n | (1 << start);
            else
                n = n & ~(1 << start);
            start--;
            end++;
        }
        return n;
    }
};