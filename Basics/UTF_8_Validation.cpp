// https://leetcode.com/problems/utf-8-validation/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    int getBits(int n) {
        vector<bool> bits;
        while(n) {
            bits.push_back(n & 1);
            n = n >> 1;
        }
        bits.resize(8, 0);
        int cnt = 0;
        for(int i = bits.size() - 1; i >= 0 && bits[i]; i--)
            cnt++;
        return cnt;
    }
public:
    bool validUtf8(vector<int>& data) {
        int i = 0;
        while(i < data.size()) {
            int bits = getBits(data[i]);
            if(bits == 0)
                i++;
            else if(bits == 1 || bits > 4)
                return false;
            else {
                if(i + bits - 1 >= data.size())
                    return false;
                for(int k = 0; k < bits - 1; k++) {
                    int j = i + k + 1;
                    if(getBits(data[j]) != 1)
                        return false;
                }
                i += bits;
            }
        }
        return true;
    }
};