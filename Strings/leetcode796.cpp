#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.size();
        if(n != goal.size())
            return false;
        for(int i = 0; i < n; i++) {
            if(s[0] == goal[i]) {
                if(goal.substr(i) == s.substr(0, n - i) && goal.substr(0, i) == s.substr(n - i))
                    return true;
            }
        }
        return false;
    }
};
