// https://www.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1
// Medium

// Given an array of size N containing only 0s, 1s, and 2s; sort the array in ascending order.
// The functions should not return anything, modify arr in-place instead.

// Example 1:
// Input: N = 5, arr[] = {0, 1, 2, 0, 1}
// Output: 0 0 1 1 2

#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    void sort012(vector<int>& arr) {
        int c = arr.size() - 1;
        int a = 0;
        int b = 0;
        while(b <= c) {
            if(arr[b] == 0) {
                swap(arr[b], arr[a]);
                a++;
                b++;
            }
            else if(arr[b] == 2) {
                swap(arr[c], arr[b]);
                c--;
            }
            else
                b++;
            // b++;
        }
    }
};