// https://www.naukri.com/code360/problems/allocate-books_1090540?leftPanelTabValue=PROBLEM

#include<bits/stdc++.h>
using namespace std;

bool isValid(vector<int>& arr, int m, int maxPages) {
    // cout << maxPages << endl;
    int pages = 0;
    for(int x : arr) {
        if(pages + x <= maxPages) 
            pages += x;
        else {
            pages = x;
            m--;
        }
        // cout << pages << " ";
    }
    // cout << endl;
    return m >= 1;
}

int findPages(vector<int>& arr, int n, int m) {
    if(m > n)
        return -1;
    int low = 0, high = 0;
    for(int x : arr) {
        low = max(low, x);
        high += x;
    }
    int ans = high;
    while(low <= high) {
        int mid = low + ((high - low) >> 1);
        if(isValid(arr, m, mid)) {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return ans;
}