// https://leetcode.com/problems/find-servers-that-handled-most-number-of-requests/
// Hard

#include<vector>
#include<unordered_map>
#include<queue>
#include<set>
#include<climits>
using namespace std;

class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        vector<int> result;
        unordered_map<int, int> serverReqCount;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
        set<int> availableServers;
        for(int i = 0; i < k && i < arrival.size(); i++) {
            pq.push({arrival[i] + load[i], i});
            serverReqCount[i]++;
        }
        for(int i = k; i < arrival.size(); i++) {
            if(availableServers.size() || (pq.size() && arrival[i] >= pq.top().first)) {
                while(pq.size() && arrival[i] >= pq.top().first) {
                    availableServers.insert(pq.top().second);
                    pq.pop();
                }                
                auto server = lower_bound(availableServers.begin(), availableServers.end(), i%k);
                if(server == availableServers.end())
                    server = availableServers.begin();
                serverReqCount[*server]++;
                pq.push({arrival[i]+load[i], *server});                    
                availableServers.erase(server);                    
            }
        }
        int maxr = INT_MIN;
        for(auto& sc: serverReqCount)
            maxr = max(maxr, sc.second);       
        for(auto& sc: serverReqCount) {
            if(sc.second == maxr)
                result.push_back(sc.first);
        }   
        return result;
    }
};