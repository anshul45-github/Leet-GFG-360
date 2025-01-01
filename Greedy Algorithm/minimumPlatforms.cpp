#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());
        int maxStations = 1;
        int curr = 1;
        int i = 1, j = 0;
        int n = arr.size();
        while(i < n) {
            if(arr[i] <= dep[j]) {
                curr++;
                i++;
            }
            else {
                curr--;
                j++;
            }
            maxStations = max(maxStations, curr);
        }
        return maxStations;
    }
};
