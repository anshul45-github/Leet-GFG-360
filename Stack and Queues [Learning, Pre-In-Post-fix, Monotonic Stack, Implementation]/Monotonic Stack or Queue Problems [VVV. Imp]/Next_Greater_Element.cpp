// https://leetcode.com/problems/next-greater-element-i/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> greatest;
        stack<int> st;
        for(int i = nums2.size() - 1; i >= 0; i--) {
            while(!st.empty()) {
                if(st.top() > nums2[i]) {
                    greatest[nums2[i]] = st.top();
                    st.push(nums2[i]);
                    break;
                }
                st.pop();
            }
            if(st.empty()) {
                greatest[nums2[i]] = -1;
                st.push(nums2[i]);
            }
        }
        for(int i = 0; i < nums1.size(); i++) {
            nums1[i] = greatest[nums1[i]];
        }
        return nums1;
    }
};
