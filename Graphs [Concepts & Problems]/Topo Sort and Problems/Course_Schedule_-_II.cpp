// https://leetcode.com/problems/course-schedule-ii/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> ans;
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& pre) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        for(auto& v : pre) {
            adj[v[1]].push_back(v[0]);
            indegree[v[0]]++;
        }
        queue<int> q;
        for(int i = 0; i < numCourses; i++) {
            if(indegree[i] == 0)
                q.push(i);
        }
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            for(int n : adj[u]) {
                if(--indegree[n] == 0)
                    q.push(n);
            }
            ans.push_back(u);
        }
        if(ans.size() == numCourses)
            return ans;
        return {};
    }
};