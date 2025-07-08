// https://leetcode.com/problems/is-subsequence/

#include <string>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int idx = 0;
        for(int i = 0; i < t.size(); i++) {
            if(s[idx] == t[i]) {
                idx++;
                if(idx == s.size())
                    return true;
            }
        }
        return idx == s.size();
    }
};