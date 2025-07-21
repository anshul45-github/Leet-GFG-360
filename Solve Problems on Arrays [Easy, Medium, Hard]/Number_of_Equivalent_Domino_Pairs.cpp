// https://leetcode.com/problems/number-of-equivalent-domino-pairs/
// 1128. Number of Equivalent Domino Pairs
// Easy

#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        for(int i = 0; i < dominoes.size(); i++)
            sort(dominoes[i].begin(), dominoes[i].end());
        sort(dominoes.begin(), dominoes.end());
        int ans = 0;
        for(int i = 0; i < dominoes.size();) {
            int a = dominoes[i][0];
            int b = dominoes[i][1];
            int cnt = 0;
            while(i < dominoes.size() && dominoes[i][0] == a && dominoes[i][1] == b) {
                i++;
                cnt++;
            }
            ans += cnt * (cnt - 1) / 2;
        }
        return ans;
    }
};