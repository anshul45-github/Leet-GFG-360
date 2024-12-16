#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if(n < 0) {
            if(n == INT_MIN) {
                return 1 / (myPow(x, -(n + 1)) * x);
            }
            return 1 / myPow(x, -n);
        }
        if(n == 0)
            return 1;
        if(n == 1)
            return x;
        double a = myPow(x, n / 2);
        return a * a * myPow(x, n % 2);
    }
};
