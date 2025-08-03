// https://leetcode.com/problems/lemonade-change/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fives = 0;
        int tens = 0;
        for(int i = 0; i < bills.size(); i++) {
            if(bills[i] == 5)
                fives++;
            else if(bills[i] == 10) {
                tens++;
                if(fives == 0)
                    return false;
                fives--;
            }
            else {
                if(tens && fives) {
                    tens--;
                    fives--;
                }
                else if(fives >= 3) {
                    fives -= 3;
                }
                else {
                    return false;
                }
            }
        }
        return true;
    }
};
