// https://leetcode.com/problems/sum-of-k-mirror-numbers/
// Hard

#include <vector>
using namespace std;

class Solution {
    long long createPalindrome(long long num, bool odd) {
        long long x = num;
        if(odd)
            x = x / 10;
        while(x > 0) {
            num = num * 10 + x % 10;
            x = x / 10;
        }
        return num;
    }
    bool isPalindrome(long long p, int k) {
        vector<int> digits;
        while(p > 0) {
            digits.push_back(p % k);
            p = p / k;
        }
        for(int i = 0, j = digits.size() - 1; i < j; i++, j--) {
            if(digits[i] != digits[j])
                return false;
        }
        return true;
    }
public:
    long long kMirror(int k, int n) {
        long long ans = 0;
        for(long long len = 1; n > 0; len *= 10) {
            for(long long i = len; n > 0 && i < len * 10; i++) {
                long long p = createPalindrome(i, true);
                if(isPalindrome(p, k)) {
                    ans += p;
                    n--;
                }
            }
            for(long long i = len; n > 0 && i < len * 10; i++) {
                long long p = createPalindrome(i, false);
                if(isPalindrome(p, k)) {
                    ans += p;
                    n--;
                }
            }
        }
        return ans;
    }
};