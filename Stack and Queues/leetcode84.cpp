#include<bits/stdc++.h>
using namespace std;

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
