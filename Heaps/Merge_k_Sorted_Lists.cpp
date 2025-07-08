// https://leetcode.com/problems/merge-k-sorted-lists/

#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Compare {
public:
    bool operator()(pair<ListNode*, int> a, pair<ListNode*, int> b) {
        if(!(a.first) || !(b.first))
            return true;
        return ((a.first) -> val) > ((b.first) -> val);
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<ListNode*, int>, vector<pair<ListNode*, int>>, Compare> pq;
        for(int i = 0; i < lists.size(); i++) {
            if(lists[i] != nullptr)
                pq.push({lists[i], i});
        }
        ListNode* ans = new ListNode(-1);
        ListNode* temp = ans;
        while(!pq.empty()) {
            pair<ListNode*, int> p = pq.top();
            if(p.first == nullptr) {
                pq.pop();
                continue;
            }
            if(lists[p.second])
                lists[p.second] = lists[p.second] -> next;
            if(lists[p.second])
                pq.push({lists[p.second], p.second});
            temp -> next = new ListNode(p.first -> val);
            temp = temp -> next;
            pq.pop();
        }
        return ans -> next;
    }
};
