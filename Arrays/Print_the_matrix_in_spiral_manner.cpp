// https://leetcode.com/problems/spiral-matrix/description/
// 54. Spiral Matrix
// Medium

#include<bits/stdc++.h>
using namespace std;

#define pb push_back

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int i = 0;
        int j = m - 1;
        int p = 0;
        int q = n - 1;
        vector<int> order;
        while(i <= j && p <= q) {
            for(int k = i; k <= j; k++) {
                order.pb(matrix[i][k]);
            }
            p++;
            for(int k = p; k <= q; k++) {
                order.pb(matrix[k][j]);
            }
            j--;
            for(int k = j; k >= i && p <= q; k--) {
                order.pb(matrix[q][k]);
            }
            q--;
            for(int k = q; k >= p && i <= j; k--) {
                order.pb(matrix[k][i]);
            }
            i++;
        }
        return order;
    }
};
