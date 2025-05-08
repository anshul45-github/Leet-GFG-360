// https://leetcode.com/problems/find-minimum-time-to-reach-last-room-ii/
// 3342. Find Minimum Time to Reach Last Room II
// Medium

#include<vector>
#include<queue>
#include<climits>
using namespace std;

class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<vector<int>> dp(moveTime.size(), vector<int>(moveTime[0].size(), INT_MAX));
        pq.push({0, 0, 0, 0});
        vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while(!pq.empty()) {
            auto p = pq.top();
            pq.pop();
            int t = p[0];
            int r = p[1];
            int c = p[2];
            if(r == moveTime.size() - 1 && c == moveTime[0].size() - 1)
                return t;
            if(t >= dp[r][c])
                continue;
            dp[r][c] = t;
            for(auto& direction : directions) {
                int y = r + direction[0];
                int x = c + direction[1];
                if(x >= 0 && y >= 0 && y < moveTime.size() && x < moveTime[0].size() && dp[y][x] == INT_MAX) {
                    int time = max(moveTime[y][x], t) + 1 + p[3];
                    pq.push({time, y, x, !p[3]});
                }
            }
        }
        return -1;
    }
};