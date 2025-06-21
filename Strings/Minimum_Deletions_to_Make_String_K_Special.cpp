// https://leetcode.com/problems/minimum-deletions-to-make-string-k-special/
// Medium

#include<string>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int> freq(26, 0);
        for(char c : word) 
            freq[c - 'a']++;
        vector<int> tmp;
        for(int i = 0; i < 26; i++) {
            if(freq[i] != 0)
                tmp.push_back(freq[i]);
        }
        sort(tmp.begin(), tmp.end());
        int j = 0;
        int sumInWindow = 0;
        int deletedLeftSum = 0;
        int totalSum = word.size();
        int mini = INT_MAX;
        for(int i = 0; i < tmp.size(); i++) {
            int from = tmp[i];
            int to = tmp[i] + k;
            while(j < tmp.size() && tmp[j] <= to)
                sumInWindow += tmp[j++];
            int deletionsRight = (totalSum - sumInWindow - deletedLeftSum) - (tmp.size() - j) * to;
            mini = min(mini, deletedLeftSum + deletionsRight);
            sumInWindow -= tmp[i];
            deletedLeftSum += tmp[i];
        }
        return mini;
    }
};