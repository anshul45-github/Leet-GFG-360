#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> mp1;
        unordered_map<char, int> mp2;
        int n = s.size();
        if(n != t.size())
            return false;
        for(int i = 0; i < n; i++) {
            mp1[s[i]]++;
            mp2[t[i]]++;
        }
        for(int i = 0; i < n; i++) {
            if(mp1[s[i]] != mp2[s[i]])
                return false;
        }
        return true;
    }
};
