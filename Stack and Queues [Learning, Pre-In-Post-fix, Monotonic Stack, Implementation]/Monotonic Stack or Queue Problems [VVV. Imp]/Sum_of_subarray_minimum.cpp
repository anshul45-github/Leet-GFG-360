// https://leetcode.com/problems/sum-of-subarray-minimums/

#include <vector>
#include <stack>
using namespace std;

#define N 1000000007

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        vector<int> nge(arr.size(), arr.size());
        vector<int> pge(arr.size(), -1);
        stack<int> st;
        for(int i = 0; i < arr.size(); i++) {
            while(!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            if(st.empty())
                pge[i] = -1;
            else
                pge[i] = st.top();
            st.push(i);
        }
        while(!st.empty())
            st.pop();
        for(int i = arr.size() - 1; i >= 0; i--) {
            while(!st.empty() && arr[st.top()] > arr[i])
                st.pop();
            if(st.empty())
                nge[i] = arr.size();
            else
                nge[i] = st.top();
            st.push(i);
        }
        long long ans = 0;
        for(int i = 0; i < arr.size(); i++) {
            ans += 1LL * arr[i] * (nge[i] - i) * (i - pge[i]);
            ans = ans % N;
        }
        return ans;
    }
};