// https://leetcode.com/problems/divisible-and-non-divisible-sums-difference/
// Easy

class Solution {
public:
    int differenceOfSums(int n, int m) {
        int num1 = n * (n + 1) / 2;
        for(int i = m; i <= n; i += m)
            num1 -= 2 * i;
        return num1;
    }
};