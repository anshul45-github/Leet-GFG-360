// https://leetcode.com/problems/maximum-manhattan-distance-after-k-changes/
// Medium

// Problem Statement:
// You are given a string s consisting of the characters 'N', 'S', 'E' and 'W', representing movements in the four cardinal directions. You can change up to k characters in the string to any of the four characters. Your task is to find the maximum Manhattan distance from the starting point (0, 0) after making these changes.
// The Manhattan distance is defined as the sum of the absolute differences of the x and y coordinates.

// Example:
// Input: s = "NSEW", k = 1
// Output: 3
// Explanation: By changing one character, we can achieve a maximum Manhattan distance of 4.

// Constraints:
// 1 <= s.length <= 10^5
// s[i] is one of 'N', 'S', 'E', 'W'
// 0 <= k <= s.length

#include<string>
using namespace std;

class Solution {
public:
    int maxDistance(string s, int k) {
        int ans = 0;
        int north = 0;
        int south = 0;
        int east = 0;
        int west = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == 'N')
                north++;
            else if(s[i] == 'S')
                south++;
            else if(s[i] == 'W')
                west++;
            else
                east++;
            int MD = abs(north - south) + abs(east - west);
            ans = max(ans, MD + min(2 * k, i + 1 - MD));
        }
        return ans;
    }
};