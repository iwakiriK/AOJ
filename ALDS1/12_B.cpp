#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
const int MAX_N =  100;
const int INFTY = (1 << 20);

int n, M[MAX_N][MAX_N];

void dijkstra() {
    int d[n];
    bool isUsed[n];
    rep(i, n) {
        d[i] = INFTY;
        isUsed[i] = false;
    }
    d[0] = 0;
    while (true) {
        int minv = INFTY, u = -1;
        rep(i, n) {
            if (minv > d[i] && !isUsed[i]) {
                u = i;
                minv = d[i];
            }
        }
        if (u == -1) break;
        isUsed[u] = true;
        rep(v, n) {
            if (!isUsed[v] && d[v] > d[u]+ M[u][v]) {
                d[v] = d[u] + M[u][v];
            }
        }
    }
    
    rep(i, n) {
        cout << i << " " << (d[i] == INFTY ? -1 : d[i]) << endl;
    }
}

int main() {
    cin >> n;
    rep(i, n) rep(j, n) {
        M[i][j] = INFTY;
    }
    
    int u, k, v, c;
    rep(i, n) {
        cin >> u >> k;
        rep(j, k) {
            cin >> v >> c;
            M[u][v] = c;
        }
    }

    dijkstra();
    
    return 0;
}
