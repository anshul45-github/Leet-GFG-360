#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDepth(string s) {
        int m = 0;
        int p = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(') {
                p++;
                m = max(m, p);
            }
            else if(s[i] == ')')
                p--;
        }
        return m;
    }
};
