// https://www.interviewbit.com/problems/subarray-with-given-xor/

#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &A, int B) {
    unordered_map<int, int> mp;
    mp[0] = 1;
    int currXor = 0;
    int ans = 0;
    for(int x : A) {
        currXor ^= x;
        // if(mp.count(currXor - k))
        ans += mp[currXor ^ B];
        mp[currXor]++;
    }
    return ans;       
}