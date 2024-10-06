#include<bits/stdc++.h>
using namespace std;

pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x) {
	int l = 0;
    int r = n - 1;
    while(l <= r) {
        int mid = l + ((r - l) >> 1);
        if(a[mid] == x) {
            pair<int, int> p;
            p.first = a[mid];
            p.second = a[mid];
            return p;
        }
        else if(a[mid] < x) {
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    pair<int, int> p;

    if(r == -1)
        p.first = -1;
    else
        p.first = a[r];
    
    if(r != -1 && a[r] == x)
        p.second = a[r];
    else
        p.second = a[r + 1] ? a[r + 1] : -1;
    return p;
}
