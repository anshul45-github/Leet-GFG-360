// https://leetcode.com/problems/minimum-domino-rotations-for-equal-row/
// 1007. Minimum Domino Rotations For Equal Row
// Medium

#include<vector>
#include<climits>
using namespace std;

class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();
        vector<int> freq(7, 0);
        for(int i = 0; i  < n; i++) {
            freq[tops[i]]++;
            freq[bottoms[i]]++;
        }
        int k = -1;
        for(int i = 1; i <= 6; i++) {
            if(freq[i] >= n) {
                k = i;
                break;
            }
        }
        if(k == -1)
            return -1;
        int takingTop = 0;
        int takingBottom = 0;
        for(int i = 0; i < n; i++) {
            if(tops[i] != k && bottoms[i] != k)
                return -1;
            else if(tops[i] == k && bottoms[i] != k)
                takingTop++;
            else if(tops[i] != k && bottoms[i] == k)
                takingBottom++;
        }
        return min(takingTop, takingBottom);
    }
};