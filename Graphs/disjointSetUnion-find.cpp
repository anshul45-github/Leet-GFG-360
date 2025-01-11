#include<bits/stdc++.h>
using namespace std;

int find(int A[],int X)
{
    if(A[X] == X)
        return X;
    return find(A, A[X]);
}
void unionSet(int A[],int X,int Z)
{
	int par = A[Z];
	A[X] = par;
}
