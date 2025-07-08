#include<bits/stdc++.h>
using namespace std;

class Solution {
    void heapify(int H[], int s, int i) {
        int largest = i;
        int left = leftChild(i);
        int right = rightChild(i);
        if(left <= s && H[largest] < H[left])
            largest = left;
        if(right <= s && H[largest] < H[right])
            largest = right;
        if(largest != i) {
            swap(H[largest], H[i]);
            heapify(H, s, largest);
        }
    }
  public:
    int extractMax() {
        int max = H[0];
        swap(H[0], H[s]);
        s--;
        
        heapify(H, s, 0);
        
        return max;
    }
};
