// Recursion
#include<bits/stdc++.h>
using namespace std;

class Solution {
    void makeCopy(stack<int>& s, stack<int>& cpy) {
        if(s.empty())
            return;
        int k = s.top();
        s.pop();
        makeCopy(s, cpy);
        cpy.push(k);
    }
    void reverse(stack<int>& s, stack<int>& cpy) {
        if(cpy.empty())
            return;
        int k = cpy.top();
        cpy.pop();
        s.push(k);
        reverse(s, cpy);
    }
public:
    void Reverse(stack<int> &St) {
        stack<int> copy;
        makeCopy(St, copy);
        reverse(St, copy);
        return;
    }
};
