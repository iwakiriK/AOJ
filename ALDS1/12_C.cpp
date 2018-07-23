#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
const int MAX_N = 10000;
const int INFTY = (1 << 20);

int n;
vector<pair<int, int> > G[MAX_N];

void dijkstra() {
    priority_queue<pair<int, int> > PQ;
    int d[n];
    bool isUsed[n];
    rep(i, n) {
        d[i] = INFTY;
        isUsed[i] = false;
    }
    d[0] = 0;
    PQ.push(make_pair(0, 0));

    while (!PQ.empty()) {
        pair<int, int> p = PQ.top(); PQ.pop();
        int u = p.second;
        isUsed[u] = true;
        if (d[u] < -p.first) continue;
        rep(i, G[u].size()) {
            int v = G[u][i].first;
            if (isUsed[v]) continue;
            if (d[v] > d[u] + G[u][i].second) {
                d[v] = d[u] + G[u][i].second;
                PQ.push(make_pair(-d[v], v));
            }
        }
    }
    
    rep(i, n) {
        cout << i << " " << (d[i] == INFTY ? -1 : d[i]) << endl;
    }
}

int main() {
    cin >> n;

    int u, k, v, c;
    rep(i, n) {
        cin >> u >> k;
        rep(j, k) {
            cin >> v >> c;
            G[u].push_back(make_pair(v, c));
        }
    }

    dijkstra();
    
    return 0;
}
