#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void createZarray(string str, int Z[]) {
        Z[0] = 0;
        int l = 0;
        int r = 0;
        for(int i = 1; i < str.size(); i++) {
            if(i > r) {
                l = i;
                r = i;
                while(r < str.size() && str[r] == str[r - l])
                    r++;
                Z[i] = r - l;
                r--;
            }
            else {
                int k1 = i - l;
                if(Z[k1] < r - i + 1)
                    Z[i] = Z[k1];
                else {
                    l = i;
                    r = i;
                    while(r < str.size() && str[r] == str[r - l])
                        r++;
                    Z[i] = r - l;
                    r--;
                }
            }
        }
    }

    int strStr(string haystack, string needle) {
        int n = needle.size() + haystack.size() + 1;
        int* Z = new int[n];
        createZarray(needle + "$" + haystack, Z);
        int i = needle.size() + 1;
        while(i < n) {
            if(Z[i] == needle.size())
                return i - needle.size() - 1;
            i++;
        }
        return -1;
    }
};
