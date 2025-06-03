// https://leetcode.com/problems/maximum-candies-you-can-get-from-boxes/
// Hard

#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        vector<bool> found(status.size(), false);
        queue<int> q;
        for(int box : initialBoxes) {
            found[box] = true;
            if(status[box] == 1)
                q.push(box);
        }
        int candy = 0;
        while(!q.empty()) {
            int box = q.front();
            q.pop();
            if(status[box] == -1)
                continue;
            for(int key : keys[box]) {
                if(status[key] == 0) {
                    status[key] = 1;
                    if(found[key])
                        q.push(key);
                }
            }
            for(int containedBox : containedBoxes[box]) {
                found[containedBox] = true;
                if(status[containedBox] == 1)
                    q.push(containedBox);
            }
            candy += candies[box];
            status[box] = -1;
        }
        return candy;
    }
};