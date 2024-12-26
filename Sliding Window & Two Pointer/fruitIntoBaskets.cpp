#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int totalFruits(vector<int> &arr) {
        int start = 0;
        unordered_map<int, int> baskets;
        int maxAns = 0;
        
        for(int end = 0; end < arr.size(); end++) {
            baskets[arr[end]]++;
            
            while(baskets.size() > 2) {
                baskets[arr[start]]--;
                if(baskets[arr[start]] == 0)
                    baskets.erase(arr[start]);
                start++;
            }
            maxAns = max(maxAns, end - start + 1);
        }
        return maxAns;
    }
};
