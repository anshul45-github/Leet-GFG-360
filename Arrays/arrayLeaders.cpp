// TC : O(N), SC : O(N)
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> leaders(int n, int arr[]) {
        vector<int> l;
        stack<int> st;
        int m = arr[n - 1];
        st.push(m);
        for(int i = n - 2; i >= 0; i--) {
            if(arr[i] >= m) {
                st.push(arr[i]);
                m = arr[i];
            }
        }
        while(!st.empty()) {
            int a = st.top();
            st.pop();
            l.push_back(a);
        }
        return l;
    }
};
