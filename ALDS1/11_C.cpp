#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define MAX_N 100
using namespace std;

bool M[MAX_N][MAX_N];
int n, u, k, v, d[MAX_N];

int main() {
    cin >> n;
    rep(i, n) {
        cin >> u >> k;
        rep(j, k) {
            cin >> v;
            M[u-1][v-1] = 1;
        }
    }
    // bfs
    rep(i, n) d[i] = INT_MAX;
    d[0] = 0;
    queue<int> q;
    q.push(0);
    while(!q.empty()) {
        int u = q.front(); q.pop();
        rep(v, n) {
            if (M[u][v] && d[v] == INT_MAX) {
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
    }
    rep(i, n) {
        cout << i+1 << " ";
        cout << (d[i] == INT_MAX ? -1 : d[i]) << endl;
    }
    return 0;
}
