#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        int mini = 0;
        int maxi = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(') {
                mini++;
                maxi++;
            }
            else if(s[i] == ')') {
                if(mini == 0 && maxi != 0)
                    maxi--;
                else {
                    mini--;
                    maxi--;
                }
            }
            else {
                if(mini != 0)
                    mini--;
                maxi++;
            }
            if(mini < 0)
                return false;
        }
        return mini == 0;
    }
};
