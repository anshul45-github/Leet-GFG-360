// https://leetcode.com/problems/divide-a-string-into-groups-of-size-k/
// Easy

#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;
        for(int i = 0; i < s.size(); i += k) {
            if(i + k - 1 < s.size())
                ans.push_back(s.substr(i, k));
            else
                ans.push_back(s.substr(i));
        }
        while(ans.back().size() < k)
            ans.back() += fill;
        return ans;
    }
};