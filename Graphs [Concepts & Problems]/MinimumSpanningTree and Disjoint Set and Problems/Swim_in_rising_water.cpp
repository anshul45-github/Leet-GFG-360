// https://leetcode.com/problems/swim-in-rising-water/

#include<bits/stdc++.h>
using namespace std;

// Approach 1 - Binary Search + DFS 
class Solution {
public:
    int n;
    vector<vector<int>> dirs{{0,1}, {1,0}, {-1,0}, {0,-1}};

    bool canReach(vector<vector<int>>& grid, int mid, int i, int j, vector<vector<bool>>& visited) {
        if (i < 0 || i >= n || j < 0 || j >= n || visited[i][j] || grid[i][j] > mid) return false;
        if (i == n - 1 && j == n - 1) return true;

        visited[i][j] = true;

        for (auto& d : dirs) {
            int ni = i + d[0], nj = j + d[1];
            if (canReach(grid, mid, ni, nj, visited)) return true;
        }
        return false;
    }

    int swimInWater(vector<vector<int>>& grid) {
        n = grid.size();
        int low = grid[0][0], high = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                high = max(high, grid[i][j]);


        while (low < high) {
            int mid = (low + high) / 2;
            vector<vector<bool>> visited(n, vector<bool>(n, false));
            if (canReach(grid, mid, 0, 0, visited)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};

// Approach 2 - Djikstra 
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({grid[0][0], 0, 0});
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        dist[0][0] = grid[0][0];
        vector<vector<int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        while(!pq.empty()) {
            auto v = pq.top();
            pq.pop();
            int d = v[0], i = v[1], j = v[2];
            if(d > dist[i][j])  
                continue;
            if(i == n - 1 && j == n - 1)
                return d;
            for(auto& dir : dirs) {
                int ni = i + dir[0], nj = j + dir[1];
                if(ni < 0 || ni >= n || nj < 0 || nj >= n)
                    continue;
                int distance = max(d, grid[ni][nj]);
                if(dist[ni][nj] > distance) {
                    dist[ni][nj] = distance;
                    pq.push({distance, ni, nj});
                }
            }
        }
        return dist[n - 1][n - 1];
    }
};

// Approach 3 - Union Find
class DisjointSet {
    vector<int> parent, size;

public:
    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int u) {
        if (parent[u] != u) parent[u] = find(parent[u]);
        return parent[u];
    }

    void unionBySize(int u, int v) {
        int pu = find(u), pv = find(v);
        if (pu == pv) return;
        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }

    bool connected(int u, int v) {
        return find(u) == find(v);
    }
};

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int total = n * n;
        DisjointSet dsu(total);
        vector<pair<int, pair<int, int>>> cells;

        // Step 1: Flatten grid with elevation and coordinates
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cells.push_back({grid[i][j], {i, j}});

        // Step 2: Sort by elevation
        sort(cells.begin(), cells.end());

        vector<vector<bool>> visited(n, vector<bool>(n, false));
        vector<vector<int>> dirs{{0,1}, {1,0}, {-1,0}, {0,-1}};

        for (auto& cell : cells) {
            int h = cell.first;
            int i = cell.second.first;
            int j = cell.second.second;
            visited[i][j] = true;
            int curr = i * n + j;

            // Union with neighbors
            for (auto& d : dirs) {
                int ni = i + d[0], nj = j + d[1];
                if (ni >= 0 && ni < n && nj >= 0 && nj < n && visited[ni][nj]) {
                    int neigh = ni * n + nj;
                    dsu.unionBySize(curr, neigh);
                }
            }

            if (dsu.connected(0, total - 1)) {
                return h;
            }
        }

        return -1; // fallback
    }
};