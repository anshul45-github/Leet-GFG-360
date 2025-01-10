#define N 100000

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        queue<pair<int, int>> q;
        q.push({start, 0});
        vector<int> dist(100000, INT_MAX);
        dist[0] = 0;
        if(start == end)
            return 0;
        while(!q.empty()) {
            int node = q.front().first;
            int steps = q.front().second;
            q.pop();
            for(auto n : arr) {
                int num = (n * node) % N;
                if(steps + 1 < dist[num]) {
                    dist[num] = steps + 1;
                    if(num == end)
                        return steps + 1;
                    q.push({num, steps + 1});
                }
            }
        }
        return -1;
    }
};
