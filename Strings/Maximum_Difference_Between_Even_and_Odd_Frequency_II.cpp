// https://leetcode.com/problems/maximum-difference-between-even-and-odd-frequency-ii/
// Hard

#include <vector>
#include <string>
#include <climits>
using namespace std;

class Solution {
    int solve(vector<vector<int>>& freq, int& k, char a, char b, int n) {
        int cnt = INT_MIN;
        int prev_a = 0;
        int prev_b = 0;
        vector<vector<int>> minFreq = {{1000000000, 1000000000}, {1000000000, 1000000000}};
        for(int l = 0, r = k - 1; r + 1 < n; r++) {
            int freq_a = freq[a - '0'][r + 1];
            int freq_b = freq[b - '0'][r + 1];
            while(r - l + 1 >= k && freq_b - prev_b >= 2) {
                minFreq[prev_a & 1][prev_b & 1] = min(minFreq[prev_a & 1][prev_b & 1], prev_a - prev_b);
                prev_a = freq[a - '0'][l + 1];
                prev_b = freq[b - '0'][l + 1];
                l++;
            }
            cnt = max(cnt, freq_a - freq_b - minFreq[1 - (freq_a & 1)][freq_b & 1]);
        }
        return cnt;
    }
public:
    int maxDifference(string s, int k) {
        vector<vector<int>> freq(5, vector<int>(s.size() + 1, 0));
        for(int i = 0; i < s.size(); i++) {
            for(int d = 0; d <= 4; d++) 
                freq[d][i + 1] = freq[d][i];
            freq[s[i] - '0'][i + 1]++;
        }
        int maxi = INT_MIN;
        for(char a = '0'; a <= '4'; a++) {
            if(freq[a - '0'][s.size()] == 0)
                continue;
            for(char b = '0'; b <= '4'; b++) {
                if(a == b || freq[b - '0'][s.size()] == 0)
                    continue;
                maxi = max(maxi, solve(freq, k, a, b, s.size() + 1));
            }
        }
        return maxi;
    }
};