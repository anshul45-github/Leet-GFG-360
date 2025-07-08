// https://www.naukri.com/code360/problems/min-heap_4691801?leftPanelTabValue=PROBLEM

#include <bits/stdc++.h> 
using namespace std;

void heapifyDown(vector<int>& heap, int size, int i) {
    if(i >= size)
        return;
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if(left < size && heap[left] < heap[smallest])
        smallest = left;
    if(right < size && heap[right] < heap[smallest])
        smallest = right;
    if(smallest != i) {
        swap(heap[smallest], heap[i]);
        heapifyDown(heap, size, smallest);
    }
}

void heapifyup(vector<int>& heap, int i) {
    int parent = (i - 1) >> 1;
    while(i > 0 && heap[i] < heap[parent]) {
        swap(heap[i], heap[parent]);
        i = parent;
        parent = (i - 1) >> 1;
    }
}

vector<int> minHeap(int n, vector<vector<int>>& q) {
    vector<int> heap;
    int size = 0;
    vector<int> ans;
    for(auto& query : q) {
        int op = query[0];
        if(op == 1) {
            ans.push_back(heap[0]);
            swap(heap[0], heap[size - 1]);
            size--;
            heapifyDown(heap, size, 0);
        }
        else {
            if(size >= heap.size())
                heap.push_back(query[1]);
            else
                heap[size] = query[1];
            size++;
            heapifyup(heap, size - 1);
        }
    }
    return ans;
}
