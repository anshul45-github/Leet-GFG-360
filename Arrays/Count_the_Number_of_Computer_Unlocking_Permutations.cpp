// https://leetcode.com/problems/count-the-number-of-computer-unlocking-permutations/
// Medium

// TC : O(N), SC : O(1)

#include <vector>
using namespace std;

#define N 1000000007

class Solution {
    int fact(int n) {
        long long x = 1;
        for(int i = 2; i <= n; i++)
            x = (1LL * x * i) % N;
        return x;
    }
public:
    int countPermutations(vector<int>& complexity) {
        int mini = complexity[0];
        for(int i = 1; i < complexity.size(); i++) {
            if(complexity[i] <= mini)
                return 0;
        }
        return fact(complexity.size() - 1);
    }
};