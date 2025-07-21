// https://leetcode.com/problems/finding-pairs-with-a-certain-sum/

#include <vector>
#include <unordered_map>
using namespace std;

class FindSumPairs {
    vector<int> nums2;
    unordered_map<int, int> freq;
    vector<int> nums1;
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this -> nums1 = nums1;
        this -> nums2 = nums2;
        for(int x : nums2)
            freq[x]++;
    }
    
    void add(int index, int val) {
        freq[nums2[index]]--;
        nums2[index] += val;
        freq[nums2[index]]++;
    }
    
    int count(int tot) {
        int ans = 0;
        for(int x : nums1)
            ans += freq[tot - x];
        return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */