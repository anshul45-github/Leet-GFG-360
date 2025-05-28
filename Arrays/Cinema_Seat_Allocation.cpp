// https://leetcode.com/problems/cinema-seat-allocation/
// Medium

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reserved) {
        int ans = 0;
        unordered_map<int,vector<int>> mp;
        for(auto& r: reserved)
            mp[r[0]].push_back(r[1]);
        ans = (n - mp.size()) * 2;
        for(auto& r : mp) {
            bool flag = 0;
            vector<bool> contains(11 , 0);
            for(int x : r.second) 
                contains[x] = 1;
            if(!contains[2] && !contains[3] && !contains[4] && !contains[5]) {
                ans++;
                flag = 1;
            }
            if(!contains[6] && !contains[7] && !contains[8] && !contains[9]) {
                ans++;
                flag = 1;
            }
            if(!flag) {
                if(!contains[4] && !contains[5] && !contains[6] && !contains[7])   
                    ans++;
            }            
        }
        
        return ans; 
    }
};