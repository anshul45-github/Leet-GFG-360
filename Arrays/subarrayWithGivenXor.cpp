#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &A, int B) {
    unordered_map<int, int> mp;
    int x = 0;
    int a = 0;
    int n = A.size();
    for(int i = 0; i < n; i++) {
        x = x ^ A[i];
        if(x == B)
            a++;
        if(mp.find(x ^ B) != mp.end())
            a += mp[x ^ B];
        mp[x]++;
    }
    return a;
}
