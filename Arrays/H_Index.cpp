// https://leetcode.com/problems/h-index/
// Medium

// Given an array of integers citations where citations[i] is the number of citations a researcher received for their ith paper, return compute the h-index of the researcher.

// The h-index is defined as the maximum value of h such that the given researcher has at least h papers with each paper having at least h citations.

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int maxi = 0;
        for(int i = citations.size() - 1; i >= 0; i--) {
            if(citations[i] >= citations.size() - i)
                maxi++;
            else
                break;
        }
        return maxi;
    }
};