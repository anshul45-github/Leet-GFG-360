// https://leetcode.com/problems/online-election/

#include<bits/stdc++.h>
using namespace std;

class TopVotedCandidate {
    vector<pair<int, int>> v;
public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        unordered_map<int, int> votes;
        int maxi = 0;
        int currentWinner = 0;
        for(int i = 0; i < persons.size(); i++) {
            votes[persons[i]]++;
            if(votes[persons[i]] >= maxi) {
                maxi = votes[persons[i]];
                currentWinner = persons[i];
            }
            v.push_back({times[i], currentWinner});
        }
        // for(int i = 0; i < v.size(); i++)
        //     cout << v[i].first << " " << v[i].second << endl;
    }
    
    int q(int t) {
        int low = 0, high = v.size() - 1;
        int ans = 0;
        while(low <= high) {
            int mid = low + ((high - low) >> 1);
            if(v[mid].first <= t) {
                ans = mid;
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
        return v[ans].second;
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */