// https://leetcode.com/problems/find-a-peak-element-ii/description/
// Medium

// This code finds a peak element in a 2D grid using a greedy approach.
// A peak element is an element that is greater than or equal to its neighbors.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int i = 0;
        int j = 0;
        while(true) {
            if(j + 1 < mat[0].size() && mat[i][j] < mat[i][j + 1])
                j++;
            else if(i + 1 < mat.size() && mat[i][j] < mat[i + 1][j])
                i++;
            else if(j - 1 >= 0 && mat[i][j] < mat[i][j - 1])
                j--;
            else if(i - 1 >= 0 && mat[i][j] < mat[i - 1][j])
                i--;
            else
                return {i, j};
        }
        return {-1, -1};
    }
};