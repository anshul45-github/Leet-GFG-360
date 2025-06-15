// https://leetcode.com/problems/max-difference-you-can-get-from-changing-an-integer/
// Medium

// This code is written in C++ and solves the "Max Difference You Can Get From Changing an Integer" problem on LeetCode.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDiff(int num) {
        string n = to_string(num);
        string cpy = n;
        char maxi = 'a';
        for(int i = 0; i < n.size(); i++) {
            if(n[i] != '9') {
                maxi = n[i];
                break;
            }
        }
        char mini = n[0];
        char minI = '1';
        if(n[0] == '1') {
            for(int i = 1; i < n.size(); i++) {
                if(n[i] != '0' && n[i] != '1') {
                    mini = n[i];
                    minI = '0';
                    break;
                }
            }
        }
        for(int i = 0; i < n.size(); i++) {
            if(n[i] == maxi)
                n[i] = '9';
            if(cpy[i] == mini) 
                cpy[i] = minI;
        }
        return stol(n) - stol(cpy);
    }
};