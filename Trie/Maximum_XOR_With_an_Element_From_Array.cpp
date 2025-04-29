// https://leetcode.com/problems/maximum-xor-with-an-element-from-array/
// 1707. Maximum XOR With an Element From Array
// Hard

#include<vector>
#include<algorithm>
using namespace std;

class Node {
public:
    Node* left;
    Node* right;
    Node() {
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
    void insert(Node* root, int x) {
        int n = 1 << 30;
        Node* temp = root;
        while(n) {
            if(n & x) {
                if(temp -> left == nullptr)
                    temp -> left = new Node();
                temp = temp -> left;
            }
            else {
                if(temp -> right == nullptr)
                    temp -> right = new Node();
                temp = temp -> right;
            }
            n = n >> 1;
        }
    }
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        Node* mp = new Node();
        vector<pair<int, pair<int, int>>> q;
        for(int i = 0; i < queries.size(); i++)
            q.push_back({queries[i][1], {queries[i][0], i}});
        int ind = 0;
        vector<int> ans(q.size(), -1);
        sort(q.begin(), q.end());
        sort(nums.begin(), nums.end());
        for(int i = 0; i < q.size(); i++) {
            while(ind < nums.size() && nums[ind] <= q[i].first) {
                insert(mp, nums[ind]);
                ind++;
            }
            int x = q[i].second.first;
            int n = 1 << 30;
            int xorVal = 0;
            Node* temp = mp;
            if(ind > 0) {
                while(temp) {
                    if(n & x) {
                        if(temp -> right) {
                            temp = temp -> right;
                            xorVal = xorVal | n;
                        }
                        else
                            temp = temp -> left;
                    }
                    else {
                        if(temp -> left) {
                            temp = temp -> left;
                            xorVal = xorVal | n;
                        }
                        else
                            temp = temp -> right;
                    }
                    n = n >> 1;
                }
                ans[q[i].second.second] = xorVal;
            }
        }
        return ans;
    }
};