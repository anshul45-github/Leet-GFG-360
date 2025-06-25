// https://leetcode.com/problems/longest-cycle-in-a-graph/
// Hard

// You are given a directed graph of n nodes numbered from 0 to n - 1, where each node has at most one outgoing edge.

// The graph is represented with a given 0-indexed array edges of size n, indicating that there is a directed edge from node i to node edges[i]. If there is no outgoing edge from node i, then edges[i] == -1.

// A cycle is a path that starts and ends at the same node. The length of a cycle is the number of edges in the cycle, and the longest cycle is the cycle with the maximum length.

// Return the length of the longest cycle in the graph. If no cycle exists, return -1.

// Example 1:
// Input: edges = [3,3,4,2,3]
// Output: 3
// Explanation: The longest cycle in the graph is the cycle consisting of nodes 2, 3, and 4.
// The cycle is 2 -> 4 -> 3 -> 2, and the length of the cycle is 3.

// Example 2:
// Input: edges = [2,-1,3,1]
// Output: -1
// Explanation: There are no cycles in the graph.

#include <vector>
using namespace std;

class Solution {
    int dfs(vector<int>& edges, vector<int>& dt, int curr, int time, vector<bool>& vis) {
        if(curr == -1)
            return -1;
        if(dt[curr])
            return time - dt[curr];
        if(vis[curr])
            return -1;
        vis[curr] = true;
        dt[curr] = time;
        int ans = dfs(edges, dt, edges[curr], time + 1, vis);
        dt[curr] = 0;
        return ans;
    }
public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        int ans = -1;
        vector<bool> vis(n, false);
        vector<int> rec(n, 0);
        for(int i = 0; i < n; i++) {
            if(!vis[i]) 
                ans = max(ans, dfs(edges, rec, i, 1, vis));
        }
        return ans;
    }
};