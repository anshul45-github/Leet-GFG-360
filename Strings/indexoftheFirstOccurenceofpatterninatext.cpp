#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int findMatching(string text, string pat) {
        if(text.size() < pat.size())
            return -1;
        for(int i = 0; i < text.size() - pat.size() + 1; i++) {
            if(text.substr(i, pat.size()) == pat)
                return i;
        }
        return -1;
    }
};
