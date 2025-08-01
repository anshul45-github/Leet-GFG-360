// Using recursion, but this will give TLE, as it is not possible to solve without dp.
#include<bits/stdc++.h>
using namespace std;

class Solution {
    void getSubsequences(unordered_set<string>& str, string s1, int i, string curr) {
        if(i == s1.size()) {
            str.insert(curr);
            return;
        }
        getSubsequences(str, s1, i + 1, curr);
        curr = curr + s1[i];
        getSubsequences(str, s1, i + 1, curr);
        return;
    }
  public:
    string betterString(string str1, string str2) {
        unordered_set<string> s1;
        unordered_set<string> s2;
        getSubsequences(s1, str1, 0, "");
        getSubsequences(s2, str2, 0, "");
        return s1.size() >= s2.size() ? str1 : str2;
    }
};
