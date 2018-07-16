#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define MAX_N 100
using namespace std;

bool M[MAX_N][MAX_N];
int n, u, k, v, d[MAX_N], f[MAX_N], t;

void dfs(int id) {
    if (d[id] != 0) return;
    d[id] = ++t;
    rep(i, n) {
        if (M[id][i]) dfs(i);
    }
    f[id] = ++t;
}

int main() {
    cin >> n;
    rep(i, n) {
        cin >> u >> k;
        rep(j, k) {
            cin >> v;
            M[u-1][v-1] = 1;
        }
    }
    rep(i, n) if (d[i] == 0) dfs(i);
    rep(i, n) {
        printf("%d %d %d\n", i+1, d[i], f[i]);
    }
    return 0;
}
