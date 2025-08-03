// https://www.naukri.com/code360/problems/distinct-characters_2221410?leftPanelTabValue=PROBLEM

#include<bits/stdc++.h>
using namespace std;

int kDistinctChars(int k, string &s) {
    int l = 0, r = 0, n = s.length(), ans = 1;
    unordered_map<char, int> cnt;
    while(r < n) {
        cnt[s[r]]++;
        while (cnt.size() > k) {
            cnt[s[l]]--;
            if(cnt[s[l]] == 0) 
                cnt.erase(s[l]);
            l++;
        }
        ans = max(ans, r - l + 1);
        r++;
    }
    return ans;
}