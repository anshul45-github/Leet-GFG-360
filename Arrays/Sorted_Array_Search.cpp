// https://www.geeksforgeeks.org/problems/who-will-win-1587115621/1

#include<bits/stdc++.h>
using namespace std;

// Two approaches: Linear Search and Binary Search

class Solution {
    bool binarySearch(vector<int>& arr, int k) {
        int low = 0, high = arr.size() - 1;
        while(low <= high) {
            int mid = low + ((high - low) >> 1);
            if(arr[mid] == k)
                return true;
            else if(arr[mid] < k)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return false;
    }
    bool linearSearch(vector<int>& arr, int k) {
        for(int i = 0; i < arr.size(); i++) {
            if(arr[i] == k)
                return true;
        }
        return false;
    }
  public:
    bool searchInSorted(vector<int>& arr, int k) {
        // return linearSearch(arr, k);

        return binarySearch(arr, k);
    }
};