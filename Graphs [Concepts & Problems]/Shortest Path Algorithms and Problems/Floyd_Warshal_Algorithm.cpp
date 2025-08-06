// https://www.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void floydWarshall(vector<vector<int>> &dist) {
        for(int via = 0; via < dist.size(); via++) {
            for(int i = 0; i < dist.size(); i++) {
                for(int j = 0; j < dist.size(); j++) {
                    if(dist[i][via] != 1e8 && dist[via][j] != 1e8)
                        dist[i][j] = min(dist[i][j], dist[i][via] + dist[via][j]);
                }
            }
        }
    }
};