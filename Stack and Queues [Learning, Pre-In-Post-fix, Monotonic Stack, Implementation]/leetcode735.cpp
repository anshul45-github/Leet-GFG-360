#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(int i = 0; i < asteroids.size(); i++) {
            if(asteroids[i] > 0)
                st.push(asteroids[i]);
            else {
                if(st.empty() || st.top() < 0)  
                    st.push(asteroids[i]);
                else {
                    while(!st.empty()) {
                        if(st.top() < 0) {
                            st.push(asteroids[i]);
                            break;
                        }
                        else if(st.top() > -asteroids[i])
                            break;
                        else if(st.top() == -asteroids[i]) {
                            st.pop();
                            break;
                        }
                        else {
                            st.pop();
                            if(st.empty()) {
                                st.push(asteroids[i]);
                                break;
                            }
                        }
                    }
                }
            }
        }
        vector<int> v(st.size());
        for(int i = st.size() - 1; i >= 0; i--) {
            v[i] = st.top();
            st.pop();
        }
        return v;
    }
};
