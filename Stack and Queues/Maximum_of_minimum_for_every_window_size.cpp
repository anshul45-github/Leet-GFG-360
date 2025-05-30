// https://www.naukri.com/code360/problems/max-of-min_982935?leftPanelTabValue=PROBLEM
// Hard

// Given an array of size N, find the maximum of the minimums of every window size in the array.

// The window size varies from 1 to N.

// The maximum of the minimums of every window size is defined as follows:
// For every window size i, find the minimum element in that window and then find the maximum of those minimums.

// Constraints:
// 1 <= N <= 10^4
// -10^9 <= arr[i] <= 10^9

// Approach: 
// Use a stack to find the next smaller element and previous smaller element for each element in the array.
// Then, calculate the range for each element and update the answer array accordingly. Finally, fill in the maximum values for each window size.

#include <bits/stdc++.h> 
using namespace std;

vector<int> maxMinWindow(vector<int> a, int n) {
    vector<int> ans(n, INT_MIN);
    vector<int> nse(n);
    vector<int> pse(n);
    stack<int> st;
    for(int i = n - 1; i >= 0; i--) {
        while(!st.empty() && a[st.top()] >= a[i]) 
            st.pop();
        if(st.empty())
            nse[i] = n - 1;
        else
            nse[i] = st.top() - 1;
        st.push(i);
    }
    while(!st.empty())
        st.pop();
    for(int i = 0; i < n; i++) {
        while(!st.empty() && a[st.top()] >= a[i])
            st.pop();
        if(st.empty())
            pse[i] = 0;
        else
            pse[i] = st.top() + 1;
        st.push(i);
    }
    for(int i = 0; i < n; i++) {
        int range = nse[i] - pse[i];
        ans[range] = max(ans[range], a[i]);
    }
    for(int i = n - 2; i >= 0; i--)
        ans[i] = max(ans[i], ans[i + 1]);
    return ans;
}