// https://leetcode.com/problems/task-scheduler/
// Medium

// Given a character array tasks, representing the tasks a CPU needs to do, where each letter represents a different task. Tasks could be done in any order. Each task is done in one unit of time. For each unit of time, the CPU could complete either one task or just be idle.

// However, there is a non-negative integer n that represents the cooldown period between two same tasks (the same letter in the array), that is that there must be at least n units of time between any two same tasks.

// Return the least number of units of times that the CPU will take to finish all the given tasks.

// Constraints:
// 1 <= tasks.length <= 10^4
// tasks[i] is an uppercase English letter.
// 0 <= n <= 100

// Example 1:
// Input: tasks = ["A","A","A","B","B","B"], n = 2
// Output: 8
// Explanation: A -> B -> idle -> A -> B -> idle -> A -> B
// The CPU will take 8 units of time to finish all tasks.

#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> mp;
        int f_max = 0;
        int tasksWithF_max = 0;
        for(char task : tasks) {
            mp[task]++;
            if(mp[task] > f_max) {
                f_max = mp[task];
                tasksWithF_max = 1;
            }
            else if(mp[task] == f_max)
                tasksWithF_max++;
        }
        return max((int)tasks.size(), (f_max - 1) * (n + 1) + tasksWithF_max);
    }
};