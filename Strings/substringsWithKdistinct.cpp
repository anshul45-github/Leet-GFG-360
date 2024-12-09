#include<bits/stdc++.h>
using namespace std;

class Solution {
    int solve(string s, int k) {
        int n = s.size();
        int noOfSubstrs = 0;
        int i = 0;
        int j = 0;
        unordered_map<char, int> mp;
        int distChar = 0;
        while(j < n) {
            if(!mp[s[j]]) {
                distChar++;
            }
            mp[s[j]]++;
            while(distChar > k) {
                mp[s[i]]--;
                if(!mp[s[i]])
                    distChar--;
                i++;
            }
            noOfSubstrs += j - i + 1;
            j++;
        }
        return noOfSubstrs;
    }
  public:
    int countSubstr(string& s, int k) {
        return solve(s, k) - solve(s, k - 1);
    }
};
