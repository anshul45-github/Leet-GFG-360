// https://leetcode.com/problems/length-of-last-word/
// Easy

// Problem Statement:
// Given a string s consisting of words and spaces, return the length of the last word in the string.
// A word is a maximal substring consisting of non-space characters only.
// A space is defined as a character that is not a word character.

// Example 1:
// Input: s = "Hello World"
// Output: 5
// Explanation: The last word is "World" with length 5.

// // Example 2:
// Input: s = "   fly me   to   the moon  "
// Output: 4
// Explanation: The last word is "moon" with length 4.

#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.size() - 1;
        while(i >= 0 && s[i] == ' ')
            i--;
        int len = 0;
        while(i >= 0 && s[i] != ' ') {
            i--;
            len++;
        }
        return len;
    }
};