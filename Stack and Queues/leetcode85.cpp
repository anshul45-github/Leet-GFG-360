#include<bits/stdc++.h>
using namespace std;

class Solution {
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
        int maxArea = 0;
        for(int i = 0; i < arr.size(); i++) {
            int left = i - psi[i];
            int right = nsi[arr.size() - i - 1] - i;
            maxArea = max(maxArea, (right + left - 1) * arr[i]);
        }
        return maxArea;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<vector<int>> hist(matrix.size(), vector<int>(matrix[0].size()));
        for(int i = 0; i < matrix[0].size(); i++) {
            int n = 1;
            for(int j = 0; j < matrix.size(); j++) {
                if(matrix[j][i] != '0') {
                    hist[j][i] = n;
                    n++;
                }
                else
                    n = 1;
            }
        }
        int maxAns = 0;
        for(int i = 0; i < matrix.size(); i++)
            maxAns = max(maxAns, largestRectangleArea(hist[i]));
        return maxAns;
    }
};
