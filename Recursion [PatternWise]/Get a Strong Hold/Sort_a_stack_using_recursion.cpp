// https://www.geeksforgeeks.org/problems/sort-a-stack/1

#include<bits/stdc++.h>
using namespace std;

class SortedStack {
public:
	stack<int> s;
	void sort();
};

void putMin(stack<int>& s, int idx, int mini, bool& added) {
    if(s.size() == idx) {
        s.push(mini);
        return;
    }
    int k = s.top();
    s.pop();
    mini = min(mini, k);
    putMin(s, idx, mini, added);
    if(k == mini && !added) {
        added = true;
        return;
    }
    s.push(k);
}

void SortedStack :: sort() {
    for(int i = 0; i < s.size(); i++) {
        bool added = false;
        putMin(s, i, INT_MAX, added);
    }
}
