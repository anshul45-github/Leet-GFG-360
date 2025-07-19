// https://www.geeksforgeeks.org/problems/bubble-sort/1

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void bubbleSort(int arr[], int n) {
        for(int i = 0; i < n - 1; i++) {
            for(int j = 0; j < n - i - 1; j++) {
                if(arr[j] > arr[j + 1])
                    swap(arr[j], arr[j + 1]);
            }
        }
        return;
    }
};
