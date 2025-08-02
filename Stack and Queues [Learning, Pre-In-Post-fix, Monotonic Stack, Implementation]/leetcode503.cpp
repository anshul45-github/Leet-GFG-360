#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> greatest(nums.size(), INT_MIN);
        stack<int> st;
        for(int i = nums.size() - 1; i >= 0; i--) {
            while(!st.empty()) {
                if(st.top() > nums[i]) {
                    greatest[i] = st.top();
                    st.push(nums[i]);
                    break;
                }
                st.pop();
            }
            if(st.empty()) {
                greatest[i] = INT_MIN;
                st.push(nums[i]);
            }
        }
        for(int i = nums.size() - 1; i >= 0; i--) {
            if(greatest[i] == INT_MIN) {
                while(!st.empty()) {
                    if(st.top() > nums[i]) {
                        greatest[i] = st.top();
                        st.push(nums[i]);
                        break;
                    }
                    st.pop();
                }
                if(st.empty()) {
                    greatest[i] = -1;
                    st.push(nums[i]);
                }
            }
        }
        for(int i = 0; i < nums.size(); i++) {
            nums[i] = greatest[i] == INT_MIN ? -1 : greatest[i];
        }
        return nums;
    }
};
