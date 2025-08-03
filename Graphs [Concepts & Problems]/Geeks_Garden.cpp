#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

int dfs(vector<string>& m, int i, int j) {
    m[i][j] = '0';
    int cnt = 1;
    for(auto& d : dirs) {
        int ni = i + d[0];
        int nj = j + d[1];
        if(ni >= 0 && ni < m.size() && nj >= 0 && nj < m[ni].size() && m[ni][nj] == '1')
            cnt += dfs(m, ni, nj);
    }
    return cnt;
}

void solve() {
    int N, M;
    cin >> N >> M;
    vector<string> m(N);
    for(int i = 0; i < N; i++) 
        cin >> m[i];
    int ans = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(m[i][j] == '1')
                ans = max(ans, dfs(m, i, j));
        }
    }
    cout << ans << endl;
}

int main() {
    int T;
    cin >> T;
    while(T--)
        solve();
	
	return 0;
}