#include<bits/stdc++.h>
using namespace std;

class Solution {
    int n;
    vector<int> soe;
    void markItsMultiples(vector<bool>& s, int n, int N) {
        int temp = 2 * n;
        while(temp <= N) {
            s[temp] = false;
            temp += n;
        }
        return;
    }
  public:
    void sieve() {
        vector<bool> s(n + 1, true);
        s[0] = false;
        s[1] = false;
        for(int i = 2; i <= n; i++) {
            if(!s[i])
                continue;
            soe.push_back(i);
            markItsMultiples(s, i, n);
        }
    }

    vector<int> findPrimeFactors(int N) {
        this -> n = N;
        sieve();
        vector<int> primeFactors;
        for(int i : soe) {
            while(N % i == 0) {
                N = N / i;
                primeFactors.push_back(i);
            }
            if(N == 1)
                break;
        }
        return primeFactors;
    }
};
