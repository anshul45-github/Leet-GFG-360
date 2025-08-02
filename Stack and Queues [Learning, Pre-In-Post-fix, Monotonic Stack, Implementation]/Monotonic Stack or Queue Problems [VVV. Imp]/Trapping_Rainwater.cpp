// https://leetcode.com/problems/trapping-rain-water/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& nums2) {
        vector<int> greatest(nums2.size(), -1);
        stack<int> st;
        for(int i = nums2.size() - 1; i >= 0; i--) {
            while(!st.empty()) {
                if(st.top() > nums2[i]) {
                    greatest[i] = st.top();
                    st.push(nums2[i]);
                    break;
                }
                st.pop();
            }
            if(st.empty()) {
                greatest[i] = -1;
                st.push(nums2[i]);
            }
        }
        while(!st.empty())
            st.pop();
        for(int i = 0; i < nums2.size(); i++) {
            while(!st.empty()) {
                if(st.top() > nums2[i]) {
                    greatest[i] = min(greatest[i], st.top());
                    st.push(nums2[i]);
                    break;
                }
                st.pop();
            }
            if(st.empty()) {
                greatest[i] = -1;
                st.push(nums2[i]);
            }
        }
        int maxH = 0;
        int begin = 0;
        for(int i = 0; i < greatest.size(); i++) {
            if(greatest[i] == -1) {
                for(int j = begin; j < i; j++) {
                    greatest[j] = maxH;
                }
                begin = i + 1;
                maxH = 0;
                greatest[i] = nums2[i];
            }
            else {
                maxH = max(maxH, greatest[i]);
            }
        }
        int area = 0;
        for(int i = 0; i < greatest.size(); i++) {
            area += (greatest[i] - nums2[i]);
        }
        return area;
    }
};
