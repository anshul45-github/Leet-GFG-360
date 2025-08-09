// https://leetcode.com/problems/valid-perfect-square/
// Easy

// This code checks if a number is a perfect square using binary search.

// The function `isPerfectSquare` takes an integer `num` as input and returns true if `num` is a perfect square, otherwise false.

// The search space is from 1 to `num`, and the mid-point is calculated using bitwise operations for efficiency.

// The function uses a long long type to avoid overflow when calculating the square of mid.

// The time complexity is O(log n) due to the binary search approach.

// The space complexity is O(1) as it uses a constant amount of space.

class Solution {
public:
    bool isPerfectSquare(int num) {
        long long l = 1;
        long long r = num;
        while(l <= r) {
            int mid = l + ((r - l) >> 1);
            long long square = 1LL * mid * mid;
            if(square == 1LL * num)
                return true;
            else if(square < 1LL * num)
                l = mid + 1LL;
            else
                r = mid - 1LL;
        }
        return false;
    }
};