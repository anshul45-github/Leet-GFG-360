// https://leetcode.com/problems/find-closest-node-to-given-two-nodes/
// Medium

// Given a directed graph of n nodes numbered from 0 to n - 1, where each node has at most one outgoing edge.

// The graph is represented with a given 0-indexed array edges of size n, indicating that there is a directed edge from node i to node edges[i]. If there is no outgoing edge from node i, then edges[i] == -1.

// Two nodes are given, node1 and node2.

// Return the node that can be reached from both node1 and node2 such that the maximum distance to reach that node is minimized. If there are multiple nodes, return the node with the smallest index. If no possible nodes exist, return -1.

// The distance between two nodes is defined as the number of edges in the path connecting them.

#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<climits>
using namespace std;

class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int i = node1;
        unordered_map<int, int> distances;
        int k = 0;
        while(i != -1 && !distances.count(i)) {
            distances[i] = k;
            k++;
            i = edges[i];
        }
        unordered_set<int> path2;
        int j = node2;
        k = 0;
        int minDist = INT_MAX;
        int closest = -1;
        while(j != -1 && path2.find(j) == path2.end()) {
            if(distances.count(j)) {
                int dist = max(k, distances[j]);
                if(dist < minDist) {
                    closest = j;
                    minDist = dist;
                }
                else if(dist == minDist)
                    closest = min(closest, j);
            }
            path2.insert(j);
            k++;
            j = edges[j];
        }
        return closest;
    }
};