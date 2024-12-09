#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<long long int> twoOddNum(long long int Arr[], long long int N)  
    {
        long long int xorOfAll = 0;
        for(long long int i = 0; i < N; i++)
            xorOfAll ^= Arr[i];
        long long int rmb = (xorOfAll & (xorOfAll - 1)) ^ xorOfAll;
        vector<long long int> b1;
        vector<long long int> b2;
        for(long long int i = 0; i < N; i++) {
            if(rmb & Arr[i])
                b1.push_back(Arr[i]);
            else
                b2.push_back(Arr[i]);
        }
        long long int a = 0;
        for(long long int i = 0; i < b1.size(); i++)
            a = a ^ b1[i];
        vector<long long int> v = {max(a, a ^ xorOfAll), min(a, a ^ xorOfAll)};
        return v;
    }
};
