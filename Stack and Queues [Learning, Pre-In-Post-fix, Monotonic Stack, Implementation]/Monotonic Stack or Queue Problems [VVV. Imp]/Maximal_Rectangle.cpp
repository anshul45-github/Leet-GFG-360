// https://leetcode.com/problems/maximal-rectangle/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    int solve(vector<int>& v) {
        vector<int> nle(v.size());
        vector<int> ple(v.size());
        stack<int> st;
        for(int i = 0; i < v.size(); i++) {
            while(!st.empty() && v[st.top()] >= v[i])
                st.pop();
            if(st.empty())
                nle[i] = -1;
            else
                nle[i] = st.top();
            st.push(i);
        }
        while(!st.empty())
            st.pop();
        for(int i = v.size() - 1; i >= 0; i--) {
            while(!st.empty() && v[st.top()] >= v[i])
                st.pop();
            if(st.empty())
                ple[i] = v.size();
            else
                ple[i] = st.top();
            st.push(i);
        }
        int maxArea = 0;
        for(int i = 0; i < v.size(); i++) 
            maxArea = max(maxArea, v[i] * (ple[i] - nle[i] - 1));        
        return maxArea;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<int> minis(matrix[0].size(), 0);
        int ans = 0;
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[0].size(); j++)
                minis[j] = (matrix[i][j] == '0' ? 0 : minis[j] + 1);
            ans = max(ans, solve(minis));
        }
        return ans;
    }
};