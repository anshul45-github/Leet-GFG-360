// https://leetcode.com/problems/find-minimum-time-to-reach-last-room-i/
// 3341. Find Minimum Time to Reach Last Room I
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
        pq.push({0, 0, 0});
        // dp[0][0] = 0;
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
                int x = c + direction[1];
                int y = r + direction[0];
                if(x >= 0 && y >= 0 && x < moveTime[0].size() && y < moveTime.size() && dp[y][x] == INT_MAX) {
                    int newTime = max(moveTime[y][x] + 1, t + 1);
                    pq.push({newTime, y, x});
                }
            }
        }
        return -1;
    }
};