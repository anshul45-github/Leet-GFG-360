// https://leetcode.com/problems/largest-rectangle-in-histogram/

#include<bits/stdc++.h>
using namespace std;

// Optimized Approach using Single Stack
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int area = 0, n = heights.size();
        for(int i = 0; i < n; i++) {
            while(!st.empty() && heights[i] < heights[st.top()]) {
                int bar = st.top(); 
                st.pop();
                int pse = st.empty() ? -1 : st.top();
                int nse = i;
                area = max(area, heights[bar] * (nse - pse - 1));
            }
            st.push(i);
        }
        while(!st.empty()) {
            int bar = st.top(); 
            st.pop();
            int pse = st.empty() ? -1 : st.top();
            int nse = n;
            area = max(area, heights[bar] * (nse - pse - 1));
            cout << area << " ";
        }
        return area;
    }
};

// Using Two Stacks Approach
class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        vector<int> nsi;
        vector<int> psi;
        stack<pair<int, int>> st;
        for(int i = 0; i < arr.size(); i++) {
            while(!st.empty() && st.top().first >= arr[i]) {
                st.pop();
            }
            psi.push_back(st.empty() ? -1 : st.top().second);
            st.push(make_pair(arr[i], i));
        }
        while(!st.empty())
            st.pop();
        for(int i = arr.size() - 1; i >= 0; i--) {
            while(!st.empty() && st.top().first > arr[i]) {
                st.pop();
            }
            nsi.push_back(st.empty() ? arr.size() : st.top().second);
            st.push(make_pair(arr[i], i));
        }
        for(int i = 0; i < arr.size(); i++)
            cout << psi[i] << " ";
        cout << endl;
        for(int i = 0; i < arr.size(); i++)
            cout << nsi[i] << " ";
        int maxArea = 0;
        for(int i = 0; i < arr.size(); i++) {
            int left = i - psi[i];
            int right = nsi[arr.size() - i - 1] - i;
            maxArea = max(maxArea, (right + left - 1) * arr[i]);
        }
        return maxArea;
    }
};
