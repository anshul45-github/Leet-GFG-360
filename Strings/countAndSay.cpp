// https://leetcode.com/problems/count-and-say/description/
// 38. Count and Say
// Medium

#include<bits/stdc++.h>
using namespace std;

class Solution {
    string solveIterative(int n) {
        string prev = "1";
        for(int i = 2; i <= n; i++) {
            string newStr = "";
            for(int j = 0; j < prev.size();) {
                char ch = prev[j];
                int cnt = 0;
                while(j < prev.size() && prev[j] == ch) {
                    j++;
                    cnt++;
                }
                newStr += to_string(cnt) + ch;
            }
            prev = newStr;
        }
        return prev;
    }
public:
    string countAndSay(int n) {
        return solveIterative(n);
    }
};