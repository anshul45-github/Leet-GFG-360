// https://leetcode.com/problems/find-closest-person/
// 3516. Find Closest Person
// Easy

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findClosest(int x, int y, int z) {
        if(abs(x - z) == abs(y - z))
            return 0;
        else if(abs(x - z) < abs(y - z))
            return 1;
        return 2;
    }
};