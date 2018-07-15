#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;

int lcs(string X, string Y) {
    int m = X.size();
    int n = Y.size();
    int c[m+1][n+1];
    rep(i, m+1) c[i][0] = 0;
    rep(i, n+1) c[0][i] = 0;
    rep(i, m) {
        rep(j, n) {
            if (X[i] == Y[j]) {
                c[i+1][j+1] = c[i][j] + 1;
            } else {
                c[i+1][j+1] = max(c[i][j+1], c[i+1][j]);
            }
        }
    }
    return c[m][n];
}

int main() {
    int q;
    string X, Y;
    cin >> q;
    rep(i, q) {
        cin >> X >> Y;
        cout << lcs(X, Y) << endl;
    }
    return 0;
}
