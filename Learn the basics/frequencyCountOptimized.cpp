#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void frequencyCount(vector<int>& arr, int N, int P) {
        for(int i = 0; i < N; i++) {
            if(arr[i] > N)
                arr[i] = 0;
        }
        for(int i = 0; i < N; i++) {
            if(arr[i] % (N + 1) > 0)
                arr[(arr[i] % (N + 1)) - 1] += N + 1;
        }
        for(int i = 0; i < N; i++)
            arr[i] = arr[i] / (N+1);
        return;
    }
};
