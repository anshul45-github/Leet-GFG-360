#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void bitManipulation(int num, int i) {
        i--;
        int getBit = num & (1 << i) ? 1 : 0;
        int setBit = num | (1 << i);
        int clearBit = num & ~(1 << i);
        cout << getBit << " " << setBit << " " << clearBit;
    }
};
