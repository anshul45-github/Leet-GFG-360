#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int l = 0, h = m - 1;
        while(l <= h) {
            int mid = l + ((h - l) >> 1);
            int maxCol = 0;
            for(int i = 1; i < n; i++) {
                if (mat[mid][i] > mat[mid][maxCol])
                    maxCol = i;
            }
            bool up = (mid == 0 || mat[mid][maxCol] > mat[mid - 1][maxCol]);
            bool down = (mid == m - 1 || mat[mid][maxCol] > mat[mid + 1][maxCol]);
            if(up && down)
                return {mid, maxCol};
            if (mid > 0 && mat[mid - 1][maxCol] > mat[mid][maxCol])
                h = mid - 1;
            else
                l = mid + 1;
        }
        return {-1, -1};
    }
};
