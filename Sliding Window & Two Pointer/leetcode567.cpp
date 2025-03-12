#include<bits/stdc++.h>
using namespace std;

// CHECK IF S1 IS A SUBSTRING OF S2
// USE TWO MAPS TO STORE THE FREQUENCY OF EACH CHARACTER
// USE TWO POINTERS TO SLIDE THE WINDOW
// IF THE WINDOW SIZE IS EQUAL TO THE SIZE OF S1, RETURN TRUE

// TIME COMPLEXITY: O(N)
// SPACE COMPLEXITY: O(1)

class Solution {
    public:
        bool checkInclusion(string s1, string s2) {
            unordered_map<int, int> o;
            unordered_map<int, int> t;
            for(char ch : s1)
                o[ch]++;
            int l = 0;
            int r = 0;
            while(r < s2.size()) {
                if(!o.count(s2[r])) {
                    t.clear();
                    l = r + 1;
                    r++;
                }
                else {
                    t[s2[r]]++;
                    while(t[s2[r]] > o[s2[r]]) {
                        t[s2[l]]--;
                        l++;
                    }
                    if(r - l + 1 == s1.size())
                        return true;
                    r++;
                }
            }
            return false;
        }
    };