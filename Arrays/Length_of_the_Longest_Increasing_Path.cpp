// https://leetcode.com/problems/length-of-the-longest-increasing-path/
// Hard

#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    int solve(const vector<vector<int>>& nums) {
        vector<int> dp;
        for(const auto& p : nums) {
            int val = p[1];
            auto it = lower_bound(dp.begin(), dp.end(), val);
            if(it == dp.end()) 
                dp.push_back(val);
            else 
                *it = val;
        }
        return dp.size();
    }
public:
    int maxPathLength(vector<vector<int>>& coordinates, int k) {
        vector<int> has = coordinates[k];
        sort(coordinates.begin(), coordinates.end(), [](const vector<int>& a, const vector<int>& b) {
            if(a[0] != b[0]) 
                return a[0] < b[0];
            return a[1] > b[1];
        });
        int current;
        for(int i = 0; i < coordinates.size(); i++) {
            if(coordinates[i] == has) {
                current = i;
                break;
            }
        }
        vector<vector<int>> left(coordinates.begin(), coordinates.begin() + current);
        vector<vector<int>> right(coordinates.begin() + current + 1, coordinates.end());
        int l = solve(filterSubset(left, has, true));  
        int r = solve(filterSubset(right, has, false)); 
        return l + r + 1;
    }
    vector<vector<int>> filterSubset(const vector<vector<int>>& nums, const vector<int>& has, bool isLeft) {
        vector<vector<int>> result;
        for(const auto& coord : nums) {
            if(isLeft) {
                if(coord[0] < has[0] && coord[1] < has[1]) 
                    result.push_back(coord);
            } 
            else {
                if(coord[0] > has[0] && coord[1] > has[1]) 
                    result.push_back(coord);
            }
        }
        return result;
    }
};