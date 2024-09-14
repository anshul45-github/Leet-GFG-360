// In-place, SC : O(m + n)
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        bool* rows = new bool[n];
        bool* cols = new bool[m];
        for(int i = 0; i < n; i++)
            rows[i] = false;
        for(int i = 0; i < m; i++)
            cols[i] = false;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!matrix[i][j]) {
                    rows[i] = true;
                    cols[j] = true;
                }
            }
        }
        for(int i = 0; i < n; i++) {
            if(rows[i]) {
                for(int j = 0; j < m; j++)
                    matrix[i][j] = 0;
            }
        }
        for(int i = 0; i < m; i++) {
            if(cols[i]) {
                for(int j = 0; j < n; j++)
                    matrix[j][i] = 0;
            }
        }
    }
};
