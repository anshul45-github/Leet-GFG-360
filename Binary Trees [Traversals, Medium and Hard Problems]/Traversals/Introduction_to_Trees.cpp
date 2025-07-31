// https://www.geeksforgeeks.org/problems/introduction-to-trees/1

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int countNodes(int i) {
        return pow(2, i - 1);
    }
};
