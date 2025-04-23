// https://leetcode.com/problems/count-the-hidden-sequences/
// 2145. Count the Hidden Sequences
// Medium

#include<vector>
#include<climits>
using namespace std;

class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long long maxCumSum = 0;
        long long minCumSum = 0;
        long long sum = 0;
        for(int i = 0; i < differences.size(); i++) {
            sum += 1LL * differences[i];
            maxCumSum = max(maxCumSum, sum);
            minCumSum = min(minCumSum, sum);
        }
        long long u = 1LL * upper - maxCumSum;
        long long l = 1LL * lower - minCumSum;
        if(u < l)
            return 0;
        return u - l + 1;
    }
};          