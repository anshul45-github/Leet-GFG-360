// https://leetcode.com/problems/count-largest-group/
// 1399. Count Largest Group
// Easy

#include<vector>
#include<climits>
using namespace std;

class Solution {
public:
    int countLargestGroup(int n) {
        vector<int> v(37, 0);
        int maxi = 0;
        for(int i = 1; i <= n; i++) {
            int j = i;
            int sum = 0;
            while(j) {
                sum += j % 10;
                j = j / 10;
            }
            v[sum]++;
            maxi = max(maxi, v[sum]);
        }
        int ans = 0;
        for(int i = 0; i <= 36; i++) {
            if(v[i] == maxi)
                ans++;
        }
        return ans;
    }
};