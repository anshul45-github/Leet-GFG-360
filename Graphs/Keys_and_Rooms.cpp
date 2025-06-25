// https://leetcode.com/problems/keys-and-rooms/
// Medium

// You are given an array of keys where keys[i] is the list of keys that you can access from room i (0-indexed).

// Each room has at most one key. Initially, you are in room 0.

// Return true if you can visit all rooms, or false otherwise.

// Example 1:
// Input: keys = [[1],[2],[3],[]]
// Output: true
// Explanation: You can visit all the rooms starting from room 0.
// - From room 0, you can go to room 1.
// - From room 1, you can go to room 2.
// - From room 2, you can go to room 3.
// - From room 3, you have no more keys, so you cannot go anywhere

// Example 2:
// Input: keys = [[1,3],[3,0,1],[2],[0]]
// Output: false
// Explanation: You can not visit all the rooms.

#include<vector>
using namespace std;

class Solution {
    void dfs(vector<vector<int>>& nums, int curr, vector<bool>& vis) {
        if(vis[curr])
            return;
        vis[curr] = true;
        for(int n : nums[curr])
            dfs(nums, n, vis);
    }
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> vis(rooms.size(), false);
        dfs(rooms, 0, vis);
        for(int i = 0; i < rooms.size(); i++) {
            if(!vis[i])
                return false;
        }
        return true;
    }
};