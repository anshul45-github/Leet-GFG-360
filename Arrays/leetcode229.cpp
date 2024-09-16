// TC : O(N), SC : O(1)
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        int a = 0;
        int b = 0;
        int c1 = 0;
        int c2 = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] == a)
                c1++;
            else if(nums[i] == b)
                c2++;
            else if(c1 == 0) {
                a = nums[i];
                c1++;
            }
            else if(c2 == 0) {
                b = nums[i];
                c2++;
            }
            else {
                c1--;
                c2--;
            }
        }
        c1 = 0;
        c2 = 0;
        for(int num : nums) {
            if(num == a)
                c1++;
            else if(num == b)
                c2++;
        }
        if(c1 > n / 3)
            ans.push_back(a);
        if(c2 > n / 3)
            ans.push_back(b);
        return ans;
    }
};
