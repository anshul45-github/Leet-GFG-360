#include<bits/stdc++.h>
using namespace std;

vector<int> Solution::prevSmaller(vector<int> &A) {
    vector<int> smaller;
    stack<int> st;
    for(int i = 0; i < A.size(); i++) {
        while(!st.empty()) {
            if(st.top() < A[i]) {
                smaller.push_back(st.top());
                st.push(A[i]);
                break;
            }
            st.pop();
        }
        if(st.empty()) {
            smaller.push_back(-1);
            st.push(A[i]);
        }
    }
    return smaller;
}
