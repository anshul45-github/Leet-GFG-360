// TC : O(N)
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long subArrayRanges(vector<int>& arr) {
        vector<int> psi;
        vector<int> nsi;
        vector<int> pli;
        vector<int> nli;
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
        while(!st.empty())
            st.pop();
        for(int i = 0; i < arr.size(); i++) {
            while(!st.empty() && st.top().first <= arr[i]) {
                st.pop();
            }
            pli.push_back(st.empty() ? -1 : st.top().second);
            st.push(make_pair(arr[i], i));
        }
        while(!st.empty())
            st.pop();
        for(int i = arr.size() - 1; i >= 0; i--) {
            while(!st.empty() && st.top().first < arr[i]) {
                st.pop();
            }
            nli.push_back(st.empty() ? arr.size() : st.top().second);
            st.push(make_pair(arr[i], i));
        }
        long long int sm = 0;
        for(int i = 0; i < arr.size(); i++) {
            long long left = i - psi[i];
            long long right = nsi[arr.size() - 1 - i] - i;
            sm = (sm + arr[i] * left * right);
        }
        long long int lg = 0;
        for(int i = 0; i < arr.size(); i++) {
            long long left = i - pli[i];
            long long right = nli[arr.size() - 1 - i] - i;
            lg = (lg + arr[i] * left * right);
        }
        return lg - sm;
    }
};
