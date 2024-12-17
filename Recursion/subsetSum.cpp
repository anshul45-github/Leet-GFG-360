#include<bits/stdc++.h>
using namespace std;

bool findSubsequences(vector<int>& arr, int target, int i, int sum) {
    if(sum == target)
        return true;
    if(sum > target || i == arr.size())
        return false;

    if(findSubsequences(arr, target, i + 1, sum + arr[i]))
        return true;
    if(findSubsequences(arr, target, i + 1, sum))
        return true;
    
    return false;
}

bool isSubsetPresent(int n, int k, vector<int> &a)
{
    return findSubsequences(a, k, 0, 0);
}
