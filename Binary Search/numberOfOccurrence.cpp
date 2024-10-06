#include<bits/stdc++.h>
using namespace std;

class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int count(int arr[], int n, int x) {
	    int l = 0;
	    int r = n - 1;
	    int idx = -1;
	    while(l <= r) {
	        int mid = l + ((r - l) >> 1);
	        if(arr[mid] == x) {
	            idx = mid;
	            break;
	        }
	        else if(arr[mid] < x)
	            l = mid + 1;
	        else
	            r = mid - 1;
	    }
	    if(idx == - 1)
	        return 0;
	    for(l = idx; l >= 0 && arr[l] == x; l--) {}
	    for(r = idx; r < n && arr[r] == x; r++) {}
	    return r - l - 1;
	}
};
