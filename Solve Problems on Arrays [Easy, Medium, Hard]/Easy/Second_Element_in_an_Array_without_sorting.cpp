// https://www.geeksforgeeks.org/problems/second-largest3735/1

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        int first = -1;
        int second = -1;
        for(int x : arr) {
            if(x > first) { 
                second = first;
                first = x;
            }
            else if(x != first)
                second = max(second, x);
        }
        return second;
    }
};