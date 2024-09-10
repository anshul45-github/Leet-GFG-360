#include<bits/stdc++.h>
using namespace std;

class Solution {
    void swap(vector<int>& a, int i, int j) {
        int k = a[i];
        a[i] = a[j];
        a[j] = k;
    }
public:
    void sortColors(vector<int>& nums) {
        int a = 0;
        int b = 0;
        int c = nums.size() - 1;
        while(b <= c) {
            if(nums[b] == 2) {
                swap(nums, b, c);
                c--;
            }
            else if(nums[b] == 1) {
                b++;
            }
            else {
                swap(nums, b, a);
                if(a == b)
                    b++;
                a++;
            }
        }
    }
};
