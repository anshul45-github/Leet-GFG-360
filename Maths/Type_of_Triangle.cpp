// https://leetcode.com/problems/type-of-triangle/
// 3024. Type of Triangle
// Easy

// Given the lengths of three sides of a triangle, determine the type of triangle they form.

// The triangle can be classified as one of the following types:

// 1. Equilateral: All three sides are equal.

// 2. Isosceles: Exactly two sides are equal.

// 3. Scalene: All three sides are different.

// 4. None: The lengths do not form a triangle.

// The function should return a string indicating the type of triangle or "none" if the lengths do not form a triangle.

#include<vector>
#include<algorithm>
#include<string>
using namespace std;

class Solution {
public:
    string triangleType(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if(nums[0] + nums[1] <= nums[2])
            return "none";
        if(nums[0] == nums[2])
            return "equilateral";
        else if(nums[0] == nums[1] || nums[1] == nums[2])
            return "isosceles";
        return "scalene";
    }
};