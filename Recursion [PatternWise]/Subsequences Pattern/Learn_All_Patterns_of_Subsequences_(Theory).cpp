// https://www.geeksforgeeks.org/problems/better-string/1

#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    unordered_map<char, int> lastPos;       // Last seen position of each character
    unordered_map<int, int> memo;

    int count(int i, const string &s) {
        if (i < 0) return 1;                 // Base case: empty string has 1 subsequence ("")

        if (memo.count(i)) return memo[i];

        int ans = 2 * count(i - 1, s);       // All subsequences with and without s[i]

        char ch = s[i];
        if (lastPos.count(ch)) {
            ans -= count(lastPos[ch] - 1, s); // Remove duplicates
        }

        lastPos[ch] = i;

        return memo[i] = ans;
    }

public:
    string betterString(string &s1, string &s2) {
        memo.clear(); lastPos.clear();
        int count1 = count(s1.size() - 1, s1);

        memo.clear(); lastPos.clear();
        int count2 = count(s2.size() - 1, s2);

        return count1 >= count2 ? s1 : s2;
    }
};  