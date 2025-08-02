// https://leetcode.com/problems/maximum-number-of-tasks-you-can-assign/
// 2071. Maximum Number of Tasks You Can Assign
// Hard

#include<vector>
#include<deque>
#include<algorithm>
using namespace std;

class Solution {
    bool canAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength, int t) {
        int i = workers.size() - 1;
        deque<int> dq;
        for(int j = t - 1; j >= 0; j--) {
            if(!dq.empty() && dq.front() >= tasks[j])
                dq.pop_front();
            else if(i >= 0 && workers[i] >= tasks[j])
                i--;
            else {
                while(i >= 0 && workers[i] + strength >= tasks[j]) {
                    dq.push_back(workers[i]);
                    i--;
                }
                if(dq.empty() || pills == 0)
                    return false;
                pills--;
                dq.pop_back();
            }
        }
        return true;
    }
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());
        int low = 0;
        int high = min(tasks.size(), workers.size());
        while(low < high) {
            int mid = (low + high + 1) >> 1;
            if(canAssign(tasks, workers, pills, strength, mid))
                low = mid;
            else
                high = mid - 1;
        }
        return low;
    }
};