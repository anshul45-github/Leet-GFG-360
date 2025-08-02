// https://www.geeksforgeeks.org/problems/the-celebrity-problem/1

#include<bits/stdc++.h>
using namespace std;    

class Solution {
  public:
    int celebrity(vector<vector<int> >& mat) {
        int i = 0, j = mat.size() - 1;
        while(i < j) {
            if(mat[i][j] == 1)
                i++;
            else
                j--;
        }
        for(int k = 0; k < mat.size(); k++) {
            if(i == k)
                continue;
            if(mat[i][k] == 1)
                return -1;
            if(mat[k][i] == 0)
                return -1;
        }
        return i;
    }
};