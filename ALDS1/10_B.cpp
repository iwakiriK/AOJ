#include <bits/stdc++.h>
#define REP(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n) REP(i,0,n)
#define MAX_N 100
using namespace std;

int main() {
    int n, p[MAX_N+1], m[MAX_N][MAX_N];
    cin >> n;
    rep(i, n) cin >> p[i] >> p[i+1];
    rep(i, n) m[i][i] = 0;
    REP(l, 2, n+1) {
        rep(i, n-l+1) {
            int j = i + l - 1;
            m[i][j] = INT_MAX;
            REP(k, i, j) {
                m[i][j] = min(m[i][j], m[i][k] + m[k+1][j] + p[i]*p[k+1]*p[j+1]);
            }
        }
    }
    cout << m[0][n-1] << endl;

    return 0;
}
