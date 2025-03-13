#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        st.push(temperatures.size() - 1);
        vector<int> idxs(temperatures.size());
        for(int i = temperatures.size() - 1; i >= 0; i--) {
            while(st.size() && temperatures[st.top()] <= temperatures[i])
                st.pop();
            if(st.empty())
                idxs[i] = i;
            else
                idxs[i] = st.top();
            st.push(i);
        }
        for(int i = 0; i < idxs.size(); i++) {
            idxs[i] = idxs[i] - i;
        }
        return idxs;
    }
};