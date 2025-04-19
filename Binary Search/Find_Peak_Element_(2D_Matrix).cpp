// https://leetcode.com/problems/find-a-peak-element-ii/description/
// 1901. Find a Peak Element II
// Medium

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int l = 0;
        int r = m - 1;
        while(l <= r) {
            int mid = l + ((r - l) >> 1);
            int maxCol = 0;
            for(int i = 1; i < n; i++) {
                if(mat[mid][maxCol] < mat[mid][i])
                    maxCol = i;
            }
            bool up = (mid == 0 || mat[mid][maxCol] > mat[mid - 1][maxCol]);
            bool down = (mid == m - 1 || mat[mid][maxCol] > mat[mid + 1][maxCol]);
            if(up && down)
                return {mid, maxCol};
            else if(up)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return {-1, -1};
    }
};
