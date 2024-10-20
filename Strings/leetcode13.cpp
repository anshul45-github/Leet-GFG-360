#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int i = 0;
        int num = 0;
        while(s[i] == 'M') {
            num += 1000;
            i++;
        }
        while(s[i] == 'D') {
            num += 500;
            i++;
        }
        while(s[i] == 'C') {
            num += 100;
            i++;
        }
        if(s[i] == 'D') {
            num += 300;
            i++;
        }
        else if(s[i] == 'M') {
            num += 800;
            i++;
        }
        while(s[i] == 'L') {
            num += 50;
            i++;
        }
        while(s[i] == 'X') {
            num += 10;
            i++;
        }
        if(s[i] == 'L') {
            num += 30;
            i++;
        }
        else if(s[i] == 'C') {
            num += 80;
            i++;
        }
        while(s[i] == 'V') {
            num += 5;
            i++;
        }
        while(s[i] == 'I') {
            num++;
            i++;
        }
        if(s[i] == 'V') {
            num += 3;
            i++;
        }
        else if(s[i] == 'X') {
            num += 8;
            i++;
        }
        return num;
    }
};
