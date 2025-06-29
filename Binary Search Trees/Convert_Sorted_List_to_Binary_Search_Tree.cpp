// https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/

#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    TreeNode* solve(ListNode* head, int sz) {
        if(sz == 0)
            return nullptr;
        ListNode* mid = head;
        for(int i = 0; i < (sz >> 1); i++)
            mid = mid -> next;
        int leftSize, rightSize;
        if(sz & 1)
            leftSize = sz >> 1, rightSize = sz >> 1;
        else
            leftSize = sz >> 1, rightSize = (sz >> 1) - 1;
        TreeNode* root = new TreeNode(mid -> val);
        root -> left = solve(head, leftSize);
        root -> right = solve(mid -> next, rightSize);
        return root;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == nullptr)
            return nullptr;
        ListNode* tail = head;
        int sz = 1;
        while(tail -> next) {
            tail = tail -> next;
            sz++;
        }
        return solve(head, sz);
    }
};