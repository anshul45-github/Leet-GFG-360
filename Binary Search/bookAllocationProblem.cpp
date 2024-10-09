#include<bits/stdc++.h>
using namespace std;

bool isValid(vector<int> a, int n, int s, int m) {
    int studentCount = 1;
    int sum = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] > s)
            return false;
        else if(sum + a[i] <= s) {
            sum += a[i];
        }
        else {
            studentCount++;
            sum = a[i];
        }
    }
    return studentCount <= m;
}

int findPages(vector<int>& arr, int n, int m) {
    if(m > n)
        return -1;
    int l = 0;
    int h = 0;
    for(int i = 0; i < n; i++) {
        h += arr[i];
    }
    int minPages = -1;
    // cout << h << " " << l << endl;
    while(l <= h) {
        int mid = l + ((h - l) >> 1);
        // cout << mid << endl
        if(isValid(arr, n, mid, m)) {
            minPages = mid;
            h = mid - 1;
        }
        else
            l = mid + 1;
    }
    return minPages;
}
