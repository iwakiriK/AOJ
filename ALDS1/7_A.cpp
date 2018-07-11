#include <bits/stdc++.h>
#define REP(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n) REP(i,0,n)
#define MAX_N 100000
using namespace std;

struct Node {
    int parent, depth;
    vector<int> child;
};
Node T[MAX_N];
int n, id, k, c, root;

void setDepth(int id, int depth) {
    T[id].depth = depth;
    rep(i, T[id].child.size()) {
        setDepth(T[id].child[i], depth+1);
    }
}

int main() {
    cin >> n;
    // parent and child
    rep(i, n) T[i].parent = -1;
    rep(i, n) {
        cin >> id >> k;
        rep(j, k) {
            cin >> c;
            T[c].parent = id;
            T[id].child.push_back(c);
        }
    }
    // depth
    rep(i, n) {
        if (T[i].parent == -1) {
            root = i;
            break;
        }
    }
    setDepth(root, 0);
    // output
    rep(i, n) {
        cout << "node " << i << ": parent = " << T[i].parent;
        cout << ", depth = " << T[i].depth << ", ";
        if (T[i].parent == -1) cout << "root, [";
        else if (T[i].child.size() == 0) cout << "leaf, [";
        else cout << "internal node, [";
        rep(j, T[i].child.size()) {
            if (j) cout << ", ";
            cout << T[i].child[j];
        }
        cout << "]" << endl;
    }
    return 0;
}
