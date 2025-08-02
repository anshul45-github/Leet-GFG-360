// https://leetcode.com/problems/maximum-average-pass-ratio/

#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double, int>> pq;
        for(int i = 0; i < classes.size(); i++) {
            double difference = double(classes[i][0] + 1) / (classes[i][1] + 1);
            difference -= double(classes[i][0]) / classes[i][1];
            pq.push({difference, i});
        }
        while(extraStudents) {
            int i = pq.top().second;
            pq.pop();
            classes[i][0]++;
            classes[i][1]++;
            double d = double(classes[i][0] + 1) / (classes[i][1] + 1);
            d -= double(classes[i][0]) / classes[i][1];
            pq.push({d, i});
            extraStudents--;
        }
        double sum = 0;
        for(int i = 0; i < classes.size(); i++)
            sum += double(classes[i][0]) / classes[i][1];
        return sum / classes.size();
    }
};