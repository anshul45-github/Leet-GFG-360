// https://www.geeksforgeeks.org/problems/quick-sort/1

#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int low, int high)
    {
        if(low >= high)
            return;
        int p = partition(arr, low, high);
        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
    
    public:
    int partition (int arr[], int low, int high)
    {
        int key = arr[high];
        int j = high - 1;
        int i = 0;
        while(i <= j) {
            if(arr[i] > key) {
                // swap(arr[j], arr[j - 1]);
                swap(arr[i], arr[j]);
                j--;
            }
            else
                i++;
        }
        swap(arr[j + 1], arr[high]);
        // arr[j] = key;
        return j + 1;
    }
};
