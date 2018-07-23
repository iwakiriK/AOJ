#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;

const int N = 8;
int row[N];
bool X[N][N], col[N], dpos[2*N-1], dneg[2*N-1];
// row: i, col: j, dpos: i + j, dneg: i - j + (N - 1)

void printBoard() {
    rep(i, N) rep(j, N) {
        if (X[i][j] && row[i] != j) return;
    }
    rep(i, N) {
        rep(j, N) {
            cout << (row[i] == j ? 'Q' : '.');
        }
        cout << endl;
    }
}

void dfs(int i) {
    if (i == N) {
        printBoard();
        return;
    }
    rep(j, N) {
        if (col[j] || dpos[i+j] || dneg[i-j+N-1]) continue;
        row[i] = j;
        col[j] = dpos[i+j] = dneg[i-j+N-1] = true;
        dfs(i+1);
        col[j] = dpos[i+j] = dneg[i-j+N-1] = false;
    }
}

int main() {
    int k, r, c;
    cin >> k;
    rep(i, k) {
        cin >> r >> c;
        X[r][c] = true;
    }

    dfs(0);

    return 0;
}
