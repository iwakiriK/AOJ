#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
const int MAX_N = 100000;

vector<int> G[MAX_N];
int color[MAX_N];

void dfs(int r, int c) {
    stack<int> S;
    S.push(r);
    color[r] = c;
    while (!S.empty()) {
        int u = S.top(); S.pop();
        rep(i, G[u].size()) {
            int v = G[u][i];
            if (color[v] == 0) {
                color[v] = c;
                S.push(v);
            }
        }
    }
}

int main() {
    // input
    int n, m, s, t, q;
    cin >> n >> m;
    rep(i, m) {
        cin >> s >> t;
        G[s].push_back(t);
        G[t].push_back(s);
    }
    // assignColor
    int id = 1;
    rep(i, n) {
        if (color[i] == 0) dfs(i, id++);
    }
    // output
    cin >> q;
    rep(i, q) {
        cin >> s >> t;
        if (color[s] == color[t]) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }
    return 0;
}
