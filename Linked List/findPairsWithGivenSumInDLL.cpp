// TC : O(N), SC : O(1)
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) {
        vector<pair<int, int>> v;
        Node* t1 = head;
        Node* t2 = head;
        while(t2 -> next)
            t2 = t2 -> next;
        while(t1 -> data < t2 -> data) {
            if(t1 -> data + t2 -> data == target) {
                pair<int, int> p;
                p.first = t1 -> data;
                p.second = t2 -> data;
                v.push_back(p);
                t1 = t1 -> next;
                t2 = t2 -> prev;
            }
            else if(t1 -> data + t2 -> data > target)
                t2 = t2 -> prev;
            else
                t1 = t1 -> next;
        }
        return v;
    }
};
