// https://leetcode.com/problems/k-th-smallest-in-lexicographical-order/
// Hard

class Solution {
    int countSteps(int n, long long curr, long long next) {
        int steps = 0;
        while(curr <= n) {
            int mini = n + 1;
            if(next < mini)
                mini = next;
            steps += mini - curr;
            curr *= 10;
            next *= 10;
        }
        return steps;
    }
public:
    int findKthNumber(int n, int k) {
        int current = 1;
        k--;
        while(k > 0) {
            int count = countSteps(n, current, current + 1);
            if(count <= k) {
                current++;
                k -= count;
            } 
            else {
                current *= 10;
                k--;
            }
        }
        return current;
    }
};