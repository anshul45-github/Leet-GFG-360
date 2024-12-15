// TC : O(N), SC : O(N)
#include<bits/stdc++.h>
using namespace std;

/*

  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution {
  public:
    // Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node* head) {
        vector<int> arr;
        Node* curr = head;
        while(curr) {
            arr.push_back(curr -> data);
            curr = curr -> next;
        }
        int a = 0;
        int b = 0;
        int c = arr.size() - 1;
        while(b <= c) {
            if(arr[b] == 1)
                b++;
            else if(arr[b] == 0) {
                swap(arr[a], arr[b]);
                a++;
                b++;
            }
            else {
                swap(arr[b], arr[c]);
                c--;
            }
        }
        curr = head;
        for(int i = 0; i < arr.size(); i++, curr = curr -> next)
            curr -> data = arr[i];
        return head;
    }
};
