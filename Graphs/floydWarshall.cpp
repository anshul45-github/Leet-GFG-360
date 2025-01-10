#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void shortestDistance(vector<vector<int>>& mat) {
        for(int i = 0; i < mat.size(); i++) {
            for(int j = 0; j < mat.size(); j++) {
                if(i == j)
                    mat[i][j] = 0;
                if(mat[i][j] == -1)
                    mat[i][j] = 1e9;
            }
        }
        for(int a = 0; a < mat.size(); a++) {
            for(int i = 0; i < mat.size(); i++) {
                for(int j = 0; j < mat.size(); j++) {
                    mat[i][j] = min(mat[i][j], mat[i][a] + mat[a][j]);
                }
            }
        }
        for(int i = 0; i < mat.size(); i++) {
            for(int j = 0; j < mat.size(); j++) {
                if(mat[i][j] == 1e9)
                    mat[i][j] = -1;
            }
        }
    }
};
