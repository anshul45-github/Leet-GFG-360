// https://www.geeksforgeeks.org/problems/minimum-multiplications-to-reach-end/1

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        queue<int> q;
        vector<bool> vis(100000, false);
        q.push(start);
        int multiplications = 0;
        while(!q.empty()) {
            int sz = q.size();
            for(int i = 0; i < sz; i++) {
                int curr = q.front();
                q.pop();
                if(vis[curr])
                    continue;
                if(curr == end)
                    return multiplications;
                vis[curr] = true;
                for(int i = 0; i < arr.size(); i++) {
                    long long temp = 1LL * curr * arr[i];
                    int x = temp % 100000;
                    if(!vis[x])
                        q.push(x);
                }
            }
            multiplications++;
        }
        return -1;
    }
};