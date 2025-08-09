// https://www.geeksforgeeks.org/problems/minimize-max-distance-to-gas-station/0

#include<bits/stdc++.h> 
using namespace std;

class Solution {
    bool isPossible(vector<int>& stations, double mid, int k) {
        int newarr = 0;
        for(int i = 0; i < stations.size() - 1; i++)
            newarr += (int)((stations[i + 1] - stations[i]) / mid); // how many newarr needed?
        return newarr <= k;
    }
  public:
    double findSmallestMaxDist(vector<int> &stations, int k) {
        int n = stations.size();
        double s = 0;
        double e = 0;
        for(int i = 0; i < n - 1; i++)
            e = max((int)e, stations[i + 1] - stations[i]);
        while(e - s > 1e-6) {
            double mid = s + (e - s) / 2.0;
            if(isPossible(stations, mid, k))
                e = mid;
            else
                s = mid;
        }
        return e;
    }
};