// https://www.geeksforgeeks.org/problems/move-all-negative-elements-to-end1813/1

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void segregateElements(vector<int>& arr) {
        vector<int> pos;
        vector<int> neg;
        vector<int> zero;
        for(int x : arr) {
            if(x >= 0)
                pos.push_back(x);
            else if(x < 0)
                neg.push_back(x);
        }
        for(int i = 0; i < pos.size(); i++)
            arr[i] = pos[i];
        for(int i = 0; i < neg.size(); i++)
            arr[i + pos.size()] = neg[i];
    }
};