// https://leetcode.com/problems/longest-repeating-character-replacement/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0;
        vector<int> freq(26, 0);
        int maxFreq = 0;
        int ans = 0;
        for(int right = 0; right < s.size(); right++) {
            maxFreq = max(maxFreq, ++freq[s[right] - 'A']);
            while(right - left + 1 - maxFreq > k) {
                freq[s[left] - 'A']--;
                int maxi = 0;
                for(int x : freq)
                    maxi = max(maxi, x);
                maxFreq = maxi;
                left++;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};