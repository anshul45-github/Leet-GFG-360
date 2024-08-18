#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void createLPSarray(string str, int lps[]) {
        int len = 0;
        int index = 1;
        lps[0] = 0;
        while(index < str.size()) {
            if(str[index] == str[len]) {
                lps[index] = len + 1;
                len++;
                index++;
            }
            else if(str[index] != str[len] && len != 0)
                len = lps[len - 1];
            else {
                lps[index] = 0;
                index++;
            }
        }
        return;
    }

    int strStr(string haystack, string needle) {
        int* lps = new int[needle.size()];
        createLPSarray(needle, lps);
        int i = 0;
        int j = 0;
        int start = 0;
        while(i < haystack.size()) {
            if(j == needle.size()) {
                return start;
            }
            if(haystack[i] == needle[j]) {
                if(start == 0)
                    start = i - j;
                i++;
                j++;
            }
            else if(haystack[i] != needle[j] && j != 0) {
                j = lps[j - 1];
                start = 0;
            }
            else {
                start = 0;
                i++;
            }
        }
        if(j == needle.size())
            return start;
        return -1;
    }
};
