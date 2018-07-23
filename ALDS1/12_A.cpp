#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
const int MAX_N =  100;
const int INFTY = (1 << 20);

int n, a[MAX_N][MAX_N];

int prim() {
    int d[n], sum = 0;
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
        sum += d[u];
        rep(v, n) {
            if (!isUsed[v] && d[v] > a[u][v]) {
                d[v] = a[u][v];
            }
        }
    }
    return sum;
}

int main() {
    cin >> n;
    int e;
    rep(i, n) rep(j, n) {
        cin >> e;
        a[i][j] = (e == -1) ? INFTY : e;
    }

    cout << prim() << endl;
    
    return 0;
}
