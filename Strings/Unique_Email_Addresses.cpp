// https://leetcode.com/problems/unique-email-addresses/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> s;
        for(auto& email : emails) {
            string str = "";
            int i;
            for(i = 0; i < email.size() && email[i] != '@'; i++) {
                if(email[i] == '.')
                    continue;
                if(email[i] == '+')
                    break;
                str += email[i];
            }
            while(email[i] != '@')
                i++;
            str += email.substr(i);
            s.insert(str);
        }
        return s.size();
    }
};