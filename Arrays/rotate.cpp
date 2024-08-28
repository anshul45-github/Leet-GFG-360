#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        int* temp1 = new int[n - k];
        int* temp2 = new int[k];
        for(int i = 0; i < n - k; i++)
            temp1[i] = nums[i];
        for(int i = n - k; i < n; i++)
            temp2[i - n + k] = nums[i];
        for(int i = 0; i < k; i++)
            nums[i] = temp2[i];
        for(int i = 0; i < n - k; i++)
            nums[i + k] = temp1[i];
        return;
    }
};
