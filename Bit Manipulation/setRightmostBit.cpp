#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int setBit(int n) {
        int i = 0;
        while((1 << i) <= n) {
            if(!(n & (1 << i))) {
                n = n | (1 << i);
                return n;
            }
            i++;
        }
        n = n | (1 << i);
        return n;
    }
};
