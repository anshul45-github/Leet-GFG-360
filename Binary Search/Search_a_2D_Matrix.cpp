// https://leetcode.com/problems/search-a-2d-matrix/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    int getRow(vector<vector<int>>& matrix, int target) {
        int l = 0;
        int h = matrix.size() - 1;
        while(l <= h) {
            int mid = l + ((h - l) >> 1);
            if(matrix[mid][0] == target)
                return mid;
            if(matrix[mid][0] < target)
                l = mid + 1;
            else
                h = mid - 1;
        }
        return h;
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r = getRow(matrix, target);
        if(r == -1)
            r = 0;
        int l = 0;
        int h = matrix[0].size() - 1;
        while(l <= h) {
            int mid = l + ((h - l) >> 1);
            if(matrix[r][mid] == target)
                return true;
            else if(matrix[r][mid] < target)
                l = mid + 1;
            else
                h = mid - 1;
        }
        return false;
    }
};
