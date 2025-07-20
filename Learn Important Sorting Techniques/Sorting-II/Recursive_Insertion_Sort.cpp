// https://www.geeksforgeeks.org/problems/insertion-sort/1

#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    void helper(int arr[], int i, int n)
    {
        if(i == n)
            return;
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
        helper(arr, i + 1, n);
    }
    public:
    void insertionSort(int arr[], int n)
    {
        helper(arr, 1, n);
    }
};
