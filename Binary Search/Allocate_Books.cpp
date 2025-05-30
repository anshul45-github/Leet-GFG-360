// https://www.interviewbit.com/problems/allocate-books/
// Medium

// Given an array of integers A of size N and an integer B.

// The array represents the number of pages in each book. You have to allocate books to B students such that the maximum number of pages assigned to a student is minimized.

// A book will be allocated to exactly one student. Each student has to be allocated at least one book.

// Return the minimum possible number of pages assigned to a student.

// NOTE: 
// Return -1 if a book cannot be allocated to any student.

// Example:
// A = [12, 34, 67, 90]
// B = 2
// The minimum possible number of pages assigned to a student is 113.

#include<bits/stdc++.h>
using namespace std;

int students(vector<int>& A, int maxi) {
    int sum = 0;
    int studentss = 1;
    for(int i = 0; i < A.size(); i++) {
        if(sum + A[i] <= maxi)
            sum += A[i];
        else {
            sum = A[i];
            studentss++;
        }
    }
    return studentss;
}

int books(vector<int> &A, int B) {
    if(A.size() < B)
        return -1;
    int low = 1;
    int high = 0;
    for(int i = 0; i < A.size(); i++) {
        low = max(low, A[i]);
        high += A[i];
    }
    while(low <= high) {
        int mid = low + ((high - low) >> 1);
        if(students(A, mid) > B)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}