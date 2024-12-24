#include<bits/stdc++.h>
using namespace std;

#define N 1000000007

class Solution {
    int mul(int a, int b, int c) {
        return ((a % N) * (b % N) * (c % N)) % N;
    }
public:
    int sumSubarrayMins(vector<int>& arr) {
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
        long long int ans = 0;
        for (int i = 0; i < arr.size(); i++) {
            long long left = i - psi[i];
            long long right = nsi[arr.size() - 1 - i] - i;
            ans = (ans + arr[i] * left * right) % N;
        }
        return ans;
    }
};
