// https://www.geeksforgeeks.org/problems/number-of-islands/0

#include<bits/stdc++.h>
using namespace std;

class Solution {
    int convert(int x, int y, int m) {
        return m * x + y;
    }
    int find(vector<int>& parent, int i) {
        if(parent[i] == i)
            return i;
        return parent[i] = find(parent, parent[i]);
    }
    void Union(vector<int>& parent, vector<int>& rank, int u, int v) {
        if(rank[u] < rank[v]) 
            parent[u] = v;
        else if(rank[v] < rank[u])
            parent[v] = u;
        else {
            parent[u] = v;
            rank[v]++;
        }
    }
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        vector<int> parent(n * m), rank(n * m, 0);
        for(int i = 0; i < n * m; i++)
            parent[i] = i;
        
        vector<int> ans;
        vector<vector<int>> grid(n, vector<int>(m, 0));
        vector<vector<int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        
        int cnt = 0;
        
        for(int i = 0; i < operators.size(); i++) {
            int x = operators[i][0], y = operators[i][1];
            
            if(grid[x][y]) {
                ans.push_back(cnt);
                continue;
            }
            
            grid[x][y] = 1;
            cnt++;
            
            int curr = convert(x, y, m);
            
            for(int j = 0; j < 4; j++) {
                int nx = x + directions[j][0];
                int ny = y + directions[j][1];
                
                if(nx < 0 || nx >= n || ny < 0 || ny >= m || !grid[nx][ny])
                    continue;
                
                int nbr = convert(nx, ny, m);
                
                int parCurr = find(parent, curr);
                int parNbr = find(parent, nbr);
                
                if(parCurr != parNbr) {
                    cnt--;
                    Union(parent, rank, parCurr, parNbr);
                }
            }
            
            ans.push_back(cnt);
        }
        
        return ans;
    }
};