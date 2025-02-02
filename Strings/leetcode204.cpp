#include<bits/stdc++.h>
using namespace std;

#define N 1000000007

class Solution {
public:
    string shortestPalindrome(string& s) {
        if(s == "")
            return s;
        long long hash = 0;
        long long revHash = 0;
        long long p_curr = 1;
        int j = s.size() - 1;
        int maxI = 0;
        for(int i = 0; i < s.size(); i++) {
            hash = ((hash * 31) + s[i]) % N;
            revHash = (revHash + (s[i] * p_curr)) % N;
            p_curr = (p_curr * 31) % N;
            if(hash == revHash)
                maxI = i;
        }
        string temp = s.substr(maxI + 1);
        reverse(temp.begin(), temp.end());
        s = temp + s;
        return s;
    }
};
