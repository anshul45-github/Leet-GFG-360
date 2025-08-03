// https://www.geeksforgeeks.org/problems/page-faults-in-lru5603/1

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int pageFaults(int N, int C, int pages[]){
        deque<int> dq;
        int faults = 0;
        for(int i = 0; i < N; i++) {
            deque<int>::iterator it;
            it = find(dq.begin(), dq.end(), pages[i]);
            if(it == dq.end()) {
                if(dq.size() == C)
                    dq.pop_front();
                dq.push_back(pages[i]);
                faults++;
            }
            else {
                dq.erase(it);
                dq.push_back(pages[i]);
            }
        }
        return faults;
    }
};
