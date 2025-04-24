// https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/
// 1423. Maximum Points You Can Obtain from Cards
// Medium

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int score = 0;
        for(int i = 0; i < k; i++)
            score += cardPoints[i];
        int maxScore = score;
        for(int i = 0; i < k; i++) {
            score = score + cardPoints[cardPoints.size() - i - 1] - cardPoints[k - i - 1];
            maxScore = max(maxScore, score);
        }
        return maxScore;
    }
};
