// https://www.interviewbit.com/problems/maximum-sum-combinations/

#include<bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> &A, vector<int> &B, int C) {
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int n = A.size();
    priority_queue<pair<int, pair<int, int>>> pq;
    for(int i = 0; i < n; i++) {
        pq.push({A[i] + B[n - 1], {i, n - 1}});
    }
    vector<int> ans;
    while(C--) {
        auto topNode = pq.top();
        pq.pop();
        int sum = topNode.first;
        int x = topNode.second.first;
        int y = topNode.second.second;
        ans.push_back(sum);
        pq.push({A[x] + B[y - 1], {x, y - 1}});
    }
    return ans;
}
