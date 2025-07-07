// https://leetcode.com/problems/largest-number/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    static bool cmp(string& a, string& b) {
        return a + b > b + a;
    }
public:
    string largestNumber(vector<int>& nums) {
        vector<string> arr;
        for(int x : nums)
            arr.push_back(to_string(x));
        sort(arr.begin(), arr.end(), cmp);
        if(arr[0] == "0")
            return "0";
        return accumulate(arr.begin(), arr.end(), string());
    }
};