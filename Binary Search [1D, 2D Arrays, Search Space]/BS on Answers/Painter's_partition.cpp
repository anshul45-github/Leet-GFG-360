// https://www.naukri.com/code360/problems/painter-s-partition-problem_1089557?leftPanelTabValue=PROBLEM

#include<bits/stdc++.h>
using namespace std;

int calculatePainters(vector<int>& boards, int maxTime) {
    int painted = 0;
    int painters = 1;
    // cout << maxTime << endl;
    for(int x : boards) {
        if(painted + x <= maxTime) 
            painted += x;
        else {
            painted = x;
            painters++;
        }
    }
    return painters;
}

int findLargestMinDistance(vector<int> &boards, int k) {
    int low = 0, high = 0;
    for(int x : boards) {
        low = max(low, x);
        high += x;
    }
    int ans = high;
    while(low <= high) {
        int mid = low + ((high - low) >> 1);
        if(calculatePainters(boards, mid) <= k) {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return ans;
}