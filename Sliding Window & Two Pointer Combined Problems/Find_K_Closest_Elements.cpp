// https://leetcode.com/problems/find-k-closest-elements/

#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int l = 0;
        int r = arr.size() - 1;
        while(r - l + 1 > k) {
            if(abs(arr[l] - x) <= abs(arr[r] - x))
                r--;
            else
                l++;
        }
        vector<int> ans(arr.begin() + l, arr.begin() + r + 1);
        return ans;
    }
};