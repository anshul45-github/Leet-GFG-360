#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string largestOddNumber(string num) {
        int i = num.size() - 1;
        while(i >= 0) {
            if((num[i] - '0') % 2 == 1)
                break;
            i--;
        }
        if(i == -1)
            return "";
        return num.substr(0, i + 1);
    }
};
