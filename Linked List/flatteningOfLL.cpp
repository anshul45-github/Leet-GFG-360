// TC : O(N * N * M), SC : O(N)
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    Node *flatten(Node *root) {
        vector<Node*> v;
        Node* horLevel = root;
        int n = 0;
        while(horLevel) {
            v.push_back(horLevel);
            horLevel = horLevel -> next;
            n++;
        }
        Node* flattenedList = new Node(-1);
        Node* curr = flattenedList;
        while(n) {
            int minNode = 0;
            while(!v[minNode])
                minNode++;
            for(int i = 0; i < v.size(); i++) {
                if(v[i] && (v[i] -> data) < (v[minNode] -> data))
                    minNode = i;
            }
            curr -> bottom = new Node(v[minNode] -> data);
            curr = curr -> bottom;
            v[minNode] = v[minNode] -> bottom;
            if(!v[minNode])
                n--;
        }
        curr = flattenedList;
        flattenedList = flattenedList -> bottom;
        delete curr;
        return flattenedList;
    }
};
