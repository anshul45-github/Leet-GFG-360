#include<bits/stdc++.h>
using namespace std;

class Solution {
    void generatePar(vector<string>& v, int n, int open, int closed, string str) {
        if(open == n && closed == n) {
            v.push_back(str);
            return;
        }
        if(open < n) {
            generatePar(v, n, open + 1, closed, str + "(");
        }
        if(open > closed) {
            generatePar(v, n, open, closed + 1, str + ")");
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> v;
        generatePar(v, n, 0, 0, "");
        return v;
    }
};
