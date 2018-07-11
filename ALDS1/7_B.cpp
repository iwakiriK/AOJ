#include <bits/stdc++.h>
#define REP(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n) REP(i,0,n)
#define MAX_N 25
using namespace std;

struct Node {
    int p = -1, left, right, dep, h;
};
Node T[MAX_N];

int n, id, l, r, root;

void setDepth(int u, int d) {
    if (u == -1) return;
    T[u].dep = d;
    setDepth(T[u].left, d + 1);
    setDepth(T[u].right, d + 1);
}

int setHeight(int u) {
    int h1 = 0, h2 = 0;
    if (T[u].left != -1) h1 = setHeight(T[u].left) + 1;
    if (T[u].right != -1) h2 = setHeight(T[u].right) + 1;
    return T[u].h = max(h1, h2);
}

int getSibling(int u) {
    int P = T[u].p;
    if (P == -1) return -1;
    if (T[P].left != u && T[P].left != -1) {
        return T[P].left;
    }
    if (T[P].right != u && T[P].right != -1) {
        return T[P].right;
    }
    return -1;
}

int main() {
    cin >> n;
    // input
    rep(i, n) {
        cin >> id >> l >> r;
        T[id].left = l;
        T[id].right = r;
        if (l != -1) T[l].p = id;
        if (r != -1) T[r].p = id;
    }
    // fill out
    rep(i, n) {
        if (T[i].p == -1) {
            root = i;
            break;
        }
    }
    setDepth(root, 0);
    setHeight(root);
    // output
    rep(i, n) {
        cout << "node " << i;
        cout << ": parent = " << T[i].p;
        cout << ", sibling = " << getSibling(i);
        int deg = 0;
        if (T[i].left != -1) deg++;
        if (T[i].right != -1) deg++;
        cout << ", degree = " << deg;
        cout << ", depth = " << T[i].dep;
        cout << ", height = " << T[i].h;
        if (T[i].p == -1) {
            cout << ", root" << endl;
        } else if (T[i].left == -1 && T[i].right == -1) {
            cout << ", leaf" << endl;
        } else {
            cout << ", internal node" << endl;
        }
    }

    return 0;
}
