// https://www.geeksforgeeks.org/problems/operations-on-binary-min-heap/1

#include<bits/stdc++.h>
using namespace std;

int heap_size = 0;
int capacity = 1000; // Initial capacity of the heap
int *harr = new int[capacity];

int parent(int i) {
    return (i - 1) / 2;
}   

int left(int i) {
    return 2 * i + 1;
}

int right(int i) {
    return 2 * i + 2;
}

int extractMin() 
{
    if(heap_size == 0)
        return -1;
    int mini = harr[0];
    swap(harr[0], harr[heap_size - 1]);
    heap_size--;
    MinHeapify(0);
    return mini;
}

//Function to delete a key at ith index.
void deleteKey(int i)
{
    if(i > heap_size - 1 || heap_size == 0)
        return;
    decreaseKey(i, INT_MIN);
    extractMin();
}

//Function to insert a value in Heap.
void insertKey(int k) 
{
    if(heap_size == capacity)
        return;
    decreaseKey(heap_size++, k);
    return;
}

//Function to change value at ith index and store that value at first index.
void decreaseKey(int i, int new_val) 
{
    harr[i] = new_val;
    while (i != 0 && harr[parent(i)] > harr[i]) {
        swap(harr[i], harr[parent(i)]);
        i = parent(i);
    }
}

/* You may call below MinHeapify function in
   above codes. Please do not delete this code
   if you are not writing your own MinHeapify */
void MinHeapify(int i) 
{
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < heap_size && harr[l] < harr[i]) smallest = l;
    if (r < heap_size && harr[r] < harr[smallest]) smallest = r;
    if (smallest != i) {
        swap(harr[i], harr[smallest]);
        MinHeapify(smallest);
    }
}
