// https://leetcode.com/problems/maximum-difference-by-remapping-a-digit/
// Easy

#include<string>
using namespace std;

class Solution {
public:
    int minMaxDifference(int num) {
        string n = to_string(num);
        char maxi = 'a';
        char mini = 'a';
        for(char ch : n) {
            if(ch != '9') {
                maxi = ch;
                break;
            }
        }
        string cpy = n;
        for(char ch : cpy) {
            if(ch != '0') {
                mini = ch;
                break;
            }
        }
        for(int i = 0; i < n.size(); i++) {
            if(n[i] == maxi)
                n[i] = '9';
            if(cpy[i] == mini)
                cpy[i] = '0';
        }
        return stoi(n) - stoi(cpy);
    }
};