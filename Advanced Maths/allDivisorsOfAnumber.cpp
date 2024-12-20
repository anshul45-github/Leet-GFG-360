#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void print_divisors(int n) {
        for(int i = 1; i * i <= n; i++) {
            if(n % i == 0)
                cout << i << " ";
        }
        int i = 1;
        while(i * i < n)
            i++;
        i--;
        for(; i >= 1; i--) {
            if(n % i == 0)
                cout << (int)(n / i) << " ";
        }
    }
};
