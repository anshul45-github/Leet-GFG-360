// https://www.geeksforgeeks.org/problems/union-of-two-sorted-arrays-1587115621/1

#include<bits/stdc++.h>
using namespace std;

// Brute Force Approach
class Solution{
    public:
    vector<int> findUnion(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
        int m = arr2.size();
        set<int> s;
        for(int i = 0; i < n; i++)
            s.insert(arr1[i]);
        for(int i = 0; i < m; i++)
            s.insert(arr2[i]);
        vector<int> unionSet;
        for(auto it = s.begin(); it != s.end(); it++)
            unionSet.push_back(*it);
        return unionSet;
    }
};

// Optimal Approach
class Solution {
  public:
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        vector<int> ans;
        int i = 0, j = 0;
        while(i < a.size() && j < b.size()) {
            int mini;
            if(a[i] < b[j]) {
                mini = a[i];
                i++;
            }
            else {
                mini = b[j];
                j++;
            }
            if(ans.size() == 0 || ans.back() < mini)
                ans.push_back(mini);
        }
        while(i < a.size()) {
            if(ans.size() == 0 || ans.back() < a[i])
                ans.push_back(a[i]);
            i++;
        }
        while(j < b.size()) {
            if(ans.size() == 0 || ans.back() < b[j])
                ans.push_back(b[j]);
            j++;
        }
        return ans;
    }
};