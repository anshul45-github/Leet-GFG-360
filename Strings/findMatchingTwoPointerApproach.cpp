#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int i = 0;
        int j = 0;
        int start = -1;
        while(i < haystack.size()) {
            if(haystack[i] == needle[j]) {
                if(j == 0)
                    start = i;
                j++;
                if(j == needle.size())
                    return start;
            }
            else {
                start = -1;
                if(j != 0) {
                    i = i - j;
                    j = 0;
                }
            }
            i++;
        }
        if(j == needle.size())
            return start;
        return -1;
    }
};
