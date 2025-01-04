#include<bits/stdc++.h>
using namespace std;

//User function Template for C++

class Solution {
public:
    bool isPossible(int a,int b)
    {
        if(a + b == 3 || a + b == 5)
            return 1;
        return 0;
    }
};
