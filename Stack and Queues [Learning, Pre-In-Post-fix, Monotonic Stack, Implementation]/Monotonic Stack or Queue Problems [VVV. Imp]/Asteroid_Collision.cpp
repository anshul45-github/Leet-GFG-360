// https://leetcode.com/problems/asteroid-collision/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(int i = 0; i < asteroids.size(); i++) {
            if(asteroids[i] < 0) {
                while(!st.empty() && st.top() < -asteroids[i] && st.top() > 0)
                    st.pop();
                if(!st.empty() && st.top() == -asteroids[i])
                    st.pop();
                else if(st.empty() || st.top() < 0)
                    st.push(asteroids[i]);
            }
            else
                st.push(asteroids[i]);
        }
        vector<int> v(st.size());
        for(int i = v.size() - 1; i >= 0; i--) {
            v[i] = st.top();
            st.pop();
        }
        return v;
    }
};