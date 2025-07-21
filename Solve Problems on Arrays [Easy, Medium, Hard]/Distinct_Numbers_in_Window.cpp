// https://www.interviewbit.com/problems/distinct-numbers-in-window/
// Medium

// Given an array A of size N and an integer B, return the number of distinct elements in every window of size B in the array A.

// Example:
// Input: A = [1, 2, 1, 3, 4, 3], B = 3
// Output: [2, 3, 3, 2]

// Explanation:
// For the first window [1, 2, 1], there are 2 distinct elements (1, 2).
// For the second window [2, 1, 3], there are 3 distinct elements (1, 2, 3).
// For the third window [1, 3, 4], there are 3 distinct elements (1, 3, 4).

// Note: The input array A can contain negative numbers and the size of the array N can be large.

// The solution uses a sliding window approach with a hash map to count distinct elements efficiently.

#include <vector>
#include <unordered_map>
using namespace std;

vector<int> dNums(vector<int> &A, int B) {
    unordered_map<int, int> mp;
    vector<int> ans;
    for(int i = 0; i < A.size(); i++) {
        mp[A[i]]++;
        if(i >= B - 1) {
            ans.push_back(mp.size());
            mp[A[i - B + 1]]--;
            if(mp[A[i - B + 1]] == 0)
                mp.erase(A[i - B + 1]);
        }
    }
    return ans;
}