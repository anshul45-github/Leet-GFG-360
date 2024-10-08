#include<bits/stdc++.h>
using namespace std;

int helper(vector<int> a, int d, int cows, int n) {
	int cowCount = 1;
	int lastEl = a[0];
	sort(a.begin(), a.end());
    int minDist = INT_MAX;
	for(int i = 1; i < n; i++) {
		int dist = a[i] - lastEl;
		if(dist >= d) {
            minDist = min(minDist, dist);
			dist = 0;
			lastEl = a[i];
			cowCount++;
		}
	}
    // cout << d << " " << cowCount << " " << minDist << endl;
	if(cowCount >= cows)
        return minDist;
    return -1;
}

int solve(vector<int> a, int n, int cows) {
	int l = 1;
	int h = a[0];
	int m = a[0];
	for(int i = 1; i < n; i++) {
		h = max(h, a[i]);
		m = min(m, a[i]);
	}
	int minDist = h - m;
	while(l <= h) {
		int mid = l + ((h - l) >> 1);
		if(helper(a, mid, cows, n) != -1) {
			l = mid + 1;
			minDist = mid;
		}
		else {
			h = mid - 1;
		}
	}
	return minDist;
}

int main() {
	int t;
	cin >> t;
	
	for(int i = 0; i < t; i++) {
		int N, C;
		cin >> N >> C;
		vector<int> x(N);
		for(int j = 0; j < N; j++)
			cin >> x[j];
		cout << solve(x, N, C) << endl;
	}
	
	return 0;
}
