#include<bits/stdc++.h>
using namespace std;

class Solution{   
public:
    int noOfSmallerNum(vector<int> a, int key) {
        int l = 0;
        int h = a.size();
        while(l < h) {
            int mid = l + ((h - l) >> 1);
            if(a[mid] <= key)
                l = mid + 1;
            else
                h = mid;
        }
        return l;
    }
    int median(vector<vector<int>> &matrix, int R, int C){
        int l = 1;
        int h = 2000;
        int median = (R * C) / 2 + 1;
        while(l < h) {
            int mid = l + ((h - l) >> 1);
            int cnt = 0;
            for(int i = 0; i < R; i++)
                cnt += noOfSmallerNum(matrix[i], mid);
            if(cnt < median)
                l = mid + 1;
            else
                h = mid;
        }
        return l;
    }
};
