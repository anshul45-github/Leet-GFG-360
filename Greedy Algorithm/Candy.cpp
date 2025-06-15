// https://leetcode.com/problems/candy/
// Hard

// This code is written in C++ and solves the "Candy" problem on LeetCode.

// The problem requires distributing candies to children based on their ratings, ensuring that each child has at least one candy and children with higher ratings receive more candies than their neighbors.

// The solution uses a greedy approach to traverse the ratings and calculate the total number of candies needed.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int sum = 1;
        int i = 1;
        while(i < ratings.size()) {
            if(ratings[i] == ratings[i - 1]) {
                i++;
                sum++;
                continue;
            }
            int peak = 1;
            while(i < ratings.size() && ratings[i] > ratings[i - 1]) {
                peak++;
                sum += peak;
                i++;
            }
            int down = 1;
            while(i < ratings.size() && ratings[i] < ratings[i - 1]) {
                sum += down;
                i++;
                down++;
            }
            if(down > peak)
                sum += down - peak;
        }
        return sum;
    }
};