// https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/
// Medium

#include<string>
#include<stack>
#include<algorithm>
using namespace std;

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<pair<int, int>> st;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(')
                st.push({1, i});
            else if(s[i] == ')') {
                if(st.empty() || st.top().first != 1)
                    st.push({-1, i});
                else
                    st.pop();
            }
        }
        string ans = "";
        for(int i = s.size() - 1; i >= 0; i--) {
            if(!st.empty() && st.top().second == i) {
                st.pop();
                continue;
            }
            ans += s[i];
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};