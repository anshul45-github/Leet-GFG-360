// https://www.geeksforgeeks.org/problems/print-1-to-n-without-using-loops-1587115620/1

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    void helper(int N, int i) {
        if(i > N)
            return;
        cout << i << " ";
        helper(N, i + 1);
        return;
    }
    
    void printNos(int N)
    {
        helper(N, 1);
        return;
    }
};