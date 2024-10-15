#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int rowWithMax1s(vector<vector<int> > &arr) {
        int n = arr.size();
        int m = arr[0].size();
        int i = 0;
        int j = m - 1;
        int maxRow = -1;
        while(i < n && j >= 0) {
            if(arr[i][j] == 1) {
                j--;
                maxRow = i;
            }
            else
                i++;
        }
        return maxRow;
        
    }
};
