#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> mp1;
        unordered_map<char, bool> mp2;
        for(int i = 0; i < s.size(); i++) {
            if(mp1.find(s[i]) == mp1.end()) {
                mp1[s[i]] = t[i];
                if(mp2[t[i]])
                    return false;
                mp2[t[i]] = true;
            }
            else if(mp1.find(s[i]) != mp1.end() && mp1[s[i]] != t[i])
                return false;
        }
        return true;
    }
};
