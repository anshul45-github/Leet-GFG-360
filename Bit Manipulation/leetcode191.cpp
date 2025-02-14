#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int hammingWeight(int n) {
        int cnt = 0;
        while(n) {
            n = n & (n - 1);
            cnt++;
        }
        return cnt;
    }
};
