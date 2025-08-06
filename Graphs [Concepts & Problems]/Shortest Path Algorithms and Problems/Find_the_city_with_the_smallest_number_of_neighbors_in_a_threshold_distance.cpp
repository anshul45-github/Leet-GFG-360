// https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/

#include<bits/stdc++.h>
using namespace std;

// Approach 1: Pretty Djikstra
// TC - O(N^3logN), SC - O(N)
class Solution {
    int get_number_of_neighbors_in_distance(int source, vector<vector<pair<int, int>>>& graph, int threshold) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> queue;
        queue.push({0, source}); // distance to node itself is 0
        unordered_set<int> visited;
        while(!queue.empty()) {
            int distance_to_this_node = queue.top().first, cur_node = queue.top().second;
            queue.pop();
            if(!visited.count(cur_node)) {
                visited.insert(cur_node);
                for(auto& p : graph[cur_node]) {
                    int neighbor = p.first, distance = p.second;
                    int dist_from_src = distance_to_this_node + distance;
                    if(dist_from_src <= threshold) // ensure that we're allowed to go to this node
                        queue.push({dist_from_src, neighbor});
                }
            }
        }
        // actually you can return visited.size() and with math there will be nothing wrong but actually we have visited.size() - 1 neighbors since we're not neighbor of ourselves
        return visited.size() - 1;
    }
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // first convert graph to adjacency list representation
        vector<vector<pair<int, int>>> graph(n); // i-th nodes will have graph[i] neighbors
        for(auto& edge : edges) {
            int node1 = edge[0], node2 = edge[1], distance = edge[2];
            graph[node1].push_back({node2, distance});
            graph[node2].push_back({node1, distance});
        }

        int minimum_number = n;
        int res = -1;

        for(int source = 0; source < n; ++source) {
            int neighbors = get_number_of_neighbors_in_distance(source, graph, distanceThreshold);
            // we iterate source from smaller to bigger this ensures that we choose node with greater value if they have equal number of neighbors
            if(neighbors <= minimum_number) {
                minimum_number = neighbors;
                res = source;
            }
        }

        return res;
    }
};

// Approach 2: Floyd-Warshall Algorithm
// TC - O(N^3), SC - O(N^2)
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        for(auto& edge : edges) {
            dist[edge[0]][edge[1]] = edge[2];
            dist[edge[1]][edge[0]] = edge[2];
        }
        for(int i = 0; i < n; i++)
            dist[i][i] = 0;
        for(int via = 0; via < n; via++) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) 
                    dist[i][j] = min(dist[i][j], dist[i][via] + dist[via][j]);
            }
        }
        int mini = INT_MAX;
        int ans = 0;
        for(int i = 0; i < n; i++) {
            int cnt = 0;
            for(int j = 0; j < n; j++) {
                if(dist[i][j] <= distanceThreshold)
                    cnt++;
            }
            if(cnt <= mini) {
                mini = cnt;
                ans = i;
            }
        }
        return ans;
    }
};