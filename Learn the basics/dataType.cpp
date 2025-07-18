#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int dataTypeSize(string str) {
        if(str == "Character")
            return 1;
        if(str == "Integer")
            return 4;
        if(str == "Float")
            return sizeof(float);
        if(str == "Long")
            return sizeof(long);
        return sizeof(double);
    }
};
