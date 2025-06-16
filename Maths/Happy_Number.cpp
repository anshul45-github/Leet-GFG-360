// https://leetcode.com/problems/happy-number/
// Easy

// Problem Statement:
// Write an algorithm to determine if a number n is happy.
// A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle that does not include 1. Those numbers for which this process ends in 1 are happy.
// Return true if n is a happy number, and false if not.

// Example 1:
// Input: n = 19
// Output: true
// Explanation: 1^2 + 9^2 = 82
// 8^2 + 2^2 = 68
// 6^2 + 8^2 = 100
// 1^2 + 0^2 + 0^2 = 1

// Example 2:
// Input: n = 2
// Output: false

#include <unordered_set>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> s;
        while(s.find(n) == s.end()) {
            s.insert(n);
            int nn = 0;
            while(n) {
                int a = n % 10;
                nn += a * a;
                n = n / 10;
            }
            if(nn == 1 || nn == 7)
                return true;
            else if(nn < 10)
                return false;
            n = nn;
        }
        return false;
    }
};