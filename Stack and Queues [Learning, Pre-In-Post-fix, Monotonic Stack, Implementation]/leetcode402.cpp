#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        if(num.length() <= k)   
            return "0";
        if(k == 0)
            return num;
        string res = "";
        stack<char> s;
        s.push(num[0]);
        for(int i = 1; i < num.size(); i++) {
            while(k && !s.empty() && s.top() > num[i]) {
                s.pop();
                k--;
            }
            s.push(num[i]);
            if(s.size() == 1 && s.top() == '0')
                s.pop();
        }
        while(k && !s.empty()) {
            k--;
            s.pop();
        }
        while(!s.empty()) {
            res.push_back(s.top());
            s.pop();
        }
        reverse(res.begin(), res.end());
        if(res.size() == 0)
            return "0";
        return res;
    }
};
