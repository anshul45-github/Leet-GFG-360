#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void printNos(int N) {
        if(N == 0)
            return;
        cout << N << " ";
        printNos(N - 1);
        return;
    }
};
