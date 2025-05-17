// https://leetcode.com/problems/sort-colors/
// 75. Sort Colors
// Medium

// Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

// We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

// You must solve this problem without using the library's sort function and in a single pass.

// Example 1:
// Input: nums = [2,0,2,1,1,0]
// Output: [0,0,1,1,2,2]

// Example 2:
// Input: nums = [2,0,1]
// Output: [0,1,2]

// Example 3:
// Input: nums = [0]
// Output: [0]

// Example 4:
// Input: nums = [1]
// Output: [1]

// Constraints:
// n == nums.length
// 1 <= n <= 300
// nums[i] is either 0, 1, or 2.

// Follow up: Could you come up with a one-pass algorithm using only constant extra space?

// Approach: Dutch National Flag Algorithm
// Time Complexity: O(n)
// Space Complexity: O(1)

// The Dutch National Flag problem is a well-known problem in computer science and combinatorial optimization. It was introduced by Edsger W. Dijkstra in 1976.

// The problem is to sort an array of objects into three distinct categories, represented by three colors: red, white, and blue. The goal is to arrange the objects in such a way that all objects of the same color are adjacent, with the colors in the order red, white, and blue.

// The algorithm uses three pointers: one for the current position (i), one for the left boundary (l), and one for the right boundary (r). The algorithm iterates through the array, swapping elements as needed to ensure that all red objects are at the beginning, all white objects are in the middle, and all blue objects are at the end.

// The algorithm works as follows:
// 1. Initialize three pointers: i = 0 (current position), l = 0 (left boundary), and r = n - 1 (right boundary).
// 2. While i is less than or equal to r:
//    a. If nums[i] is 1 (white), increment i.
//    b. If nums[i] is 0 (red), swap nums[i] with nums[l], increment both i and l.
//    c. If nums[i] is 2 (blue), swap nums[i] with nums[r], decrement r.
// 3. Repeat steps 2 until i is greater than r.
// 4. The array is now sorted in the order red, white, and blue.

// The algorithm is efficient because it only requires a single pass through the array (O(n) time complexity) and uses a constant amount of extra space (O(1) space complexity). This makes it suitable for sorting large arrays with minimal overhead.

// The algorithm is also stable, meaning that the relative order of equal elements is preserved. This is important in many applications where the order of elements matters.

// The Dutch National Flag problem is a classic example of a sorting problem that can be solved using a two-pointer technique. It is often used in interviews and coding challenges to test a candidate's understanding of sorting algorithms and their ability to optimize solutions for space and time complexity.

// The algorithm is also applicable to other problems where elements need to be partitioned into multiple categories, such as sorting an array of objects with multiple attributes or filtering data based on specific criteria.

// The algorithm is efficient and easy to implement, making it a popular choice for solving sorting problems in competitive programming and software development.


#include<vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i = 0;
        int l = 0;
        int r = nums.size() - 1;
        while(i <= r) {
            if(nums[i] == 1)
                i++;
            else if(nums[i] == 0) {
                swap(nums[i], nums[l]);
                l++;
                i++;
            }
            else {
                swap(nums[i], nums[r]);
                r--;
            }
        }
    }
};