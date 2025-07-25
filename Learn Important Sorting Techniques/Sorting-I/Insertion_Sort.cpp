// https://www.geeksforgeeks.org/problems/insertion-sort/1

#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    void insert(int arr[], int i)
    {
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    public:
    void insertionSort(int arr[], int n)
    {
        for(int i = 1; i < n; i++) {
            insert(arr, i);
        }
    }
};
