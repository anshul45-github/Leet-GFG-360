// https://leetcode.com/problems/find-the-longest-valid-obstacle-course-at-each-position/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    int findUpperBound(vector<int>& arr, int target) {
        int low = 0;
        int high = arr.size() - 1;
        int ans = high + 1;
        while(low <= high) {
            int mid = low + ((high - low) >> 1);
            if(arr[mid] > target) {
                ans = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        return ans;
    }
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        vector<int> ans = {1};
        vector<int> temp = {obstacles[0]};
        for(int i = 1; i < obstacles.size(); i++) {
            int ub = findUpperBound(temp, obstacles[i]);
            if(ub == temp.size())
                temp.push_back(obstacles[i]);
            else
                temp[ub] = obstacles[i];
            ans.push_back(ub + 1);
        }
        return ans;
    }
};