// https://leetcode.com/problems/minimum-pair-removal-to-sort-array-ii/
// 3510. Minimum Pair Removal to Sort Array II
// Hard

#include<vector>
#include<set>
using namespace std;

class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        vector<long long> a;
        for(int x : nums)
            a.push_back(1LL * x);
        set<pair<long long, int>> s;
        int cnt = 0;
        for(int i = 0; i < nums.size() - 1; i++) {
            s.insert({a[i] + a[i + 1], i});
            if(nums[i] > nums[i + 1])
                cnt++;
        }
        vector<int> pre(nums.size());
        vector<int> nxt(nums.size());
        for(int i = 0; i < nums.size(); i++) {
            pre[i] = i - 1;
            nxt[i] = i + 1;
        }
        int ans = 0;
        while(cnt) {
            ans++;
            int i = s.begin() -> second;
            int p = pre[i];
            int q = nxt[i];
            int r = nxt[q];
            if(a[i] > a[q])
                cnt--;
            if(p >= 0) {
                if(a[p] > a[i] && a[p] <= a[i] + a[q])
                    cnt--;
                else if(a[p] <= a[i] && a[p] > a[i] + a[q])
                    cnt++;
            }
            if(r < nums.size()) {
                if(a[q] > a[r] && a[i] + a[q] <= a[r])
                    cnt--;
                else if(a[q] <= a[r] && a[i] + a[q] > a[r])
                    cnt++;
            }
            s.erase(s.begin());
            nxt[i] = r;
            if(r < nums.size()) {
                s.erase({a[q] + a[r], q});
                s.insert({a[i] + a[q] + a[r], i});
                pre[r] = i;
            }
            if(p >= 0) {
                s.erase({a[p] + a[i], p});
                s.insert({a[p] + a[i] + a[q], p});
            }
            a[i] = a[i] + a[q];
        }
        return ans;
    }
};