#include<bits/stdc++.h>
using namespace std;

class Solution {
    void markItsMultiples(vector<bool>& sieve, int n, int N) {
        int temp = 2 * n;
        while(temp < N) {
            sieve[temp] = false;
            temp += n;
        }
        return;
    }
public:
    int countPrimes(int n) {
        if(n <= 0)
            return 0;
        vector<bool> sieve(n, true);
        sieve[0] = false;
        sieve[1] = false;
        int cnt = 0;
        for(int i = 2; i < n; i++) {
            if(!sieve[i])
                continue;
            cnt++;
            markItsMultiples(sieve, i, n);
        }
        return cnt;
    }
};
