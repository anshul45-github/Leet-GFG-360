// https://leetcode.com/problems/count-the-number-of-arrays-with-k-matching-adjacent-elements/
// Hard

#define mod 1000000007
class Solution {
public:
    long long mo(long long x, int exp){
        if(exp == 0) 
            return 1;
        int y = (exp & 1) ? x : 1;
        return mo(x * x % mod, exp >> 1) * y % mod;
    }
    int modInverse(int a, int b) {
        int x0 = 1, x1 = 0;
        int r0 = a, r1 = b;
        while(r1 != 0) {
            int q = r0 / r1, rr = r1, xx = x1;
            r1 = r0 - q * r1;
            x1 = x0 - q * x1;
            r0 = rr;
            x0 = xx;
        }
        if(x0 < 0) 
            x0 += b;
        return x0;
    }
    long long comb(int n, int k){
        if(n < 2 * k) 
            return comb(n, n - k);
        long long denominator = 1;
        for(int i = 1; i <= k; i++) {
            denominator *= i;
            if(denominator > mod) 
                denominator %= mod;
        }
        long long ans = modInverse(denominator, mod);
        for(int i = n; i >= n - k + 1; i--) {
            ans *= i;
            if(ans > mod) 
                ans %= mod;
        }
        return ans;
    }
    int countGoodArrays(int n, int m, int k) {
        return m * mo(m - 1, n - k - 1) % mod * comb(n - 1, k) % mod;    
    }
};