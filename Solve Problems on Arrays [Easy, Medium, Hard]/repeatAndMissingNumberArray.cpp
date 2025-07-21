#include<bits/stdc++.h>
using namespace std;

vector<int> repeatedNumber(const vector<int>& A) {
    long sum = 0;
    long long sqSum = 0;
    for(int i = 1; i <= A.size(); i++) {
        sum += 1LL*i;
        sqSum += (1LL*i) * (1LL*i);
    }
    for(int i = 0; i < A.size(); i++) {
        sum -= A[i];
        sqSum -= (1LL * A[i]) * (1LL * A[i]);
    }
    long long yMinusX = sum;
    long long yPlusX = sqSum / sum;
    int y = (yMinusX + yPlusX) / 2;
    int x = yPlusX - y;
    vector<int> v = {x, y};
    return v;
}