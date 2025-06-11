// https://leetcode.com/problems/maximal-rectangle/
// Hard

// Given a binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

// Example 1:
// Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
// Output: 6

// Example 2:
// Input: matrix = [["0"]]
// Output: 0

// Example 3:
// Input: matrix = [["1"]]
// Output: 1

// Constraints:
// 1 <= matrix.length <= 200
// 1 <= matrix[i].length <= 200
// All matrix[i].length's are equal.
// matrix[i][j] is '0' or '1'.

// Time complexity: O(m * n)
// Space complexity: O(m)

// This code is written in C++ and uses the STL library for data structures and algorithms. 

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