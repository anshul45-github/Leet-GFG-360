// https://www.geeksforgeeks.org/problems/java-if-else-decision-making0924/1

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string compareNM(int n, int m){
        if(n < m)
            return "lesser";
        else if(n == m)
            return "equal";
        else
            return "greater";
    }
};