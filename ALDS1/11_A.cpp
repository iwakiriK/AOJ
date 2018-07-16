#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define MAX_N 100
using namespace std;

bool M[MAX_N][MAX_N];
int n, u, k, v;

int main() {
    cin >> n;
    rep(i, n) {
        cin >> u >> k;
        rep(j, k) {
            cin >> v;
            M[u-1][v-1] = 1;
        }
    }
    rep(i, n) {
        rep(j, n) {
            if (j) cout << " ";
            cout << M[i][j];
        }
        cout << endl;
    }
    return 0;
}
