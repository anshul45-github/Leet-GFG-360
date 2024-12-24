// TC :  O(N * queries), SC : O(queries)
#include<bits/stdc++.h>
using namespace std;

class Solution{
public:

    vector<int> count_NGE(int n, vector<int> &arr, int queries, vector<int> &indices){
        for(int i = 0; i < queries; i++) {
            int greater = 0;
            for(int j = indices[i]; j < n; j++) {
                if(arr[j] > arr[indices[i]])
                    greater++;
            }
            indices[i] = greater;
        }
        return indices;
    }

};
