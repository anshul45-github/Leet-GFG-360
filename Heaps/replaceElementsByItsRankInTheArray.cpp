// TC : O(nlogn), SC : O(n)

class cmp {
public:
    bool operator() (pair<int, int> p1, pair<int, int> p2) {
        return p1.first > p2.first;
    }
};

class Solution{
public:

    vector<int> replaceWithRank(vector<int> &arr, int N){
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
        for(int i = 0; i < N; i++)
            pq.push({arr[i], i});
        int i = 1;
        int prev = -1;
        while(!pq.empty()) {
            arr[pq.top().second] = (pq.top().first == prev ? i - 1 : i);
            if(pq.top().first != prev)
                i++;
            prev = pq.top().first;
            pq.pop();
        }
        return arr;
    }

};
