#include <bits/stdc++.h>
#define REP(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n) REP(i,0,n)
#define MAX_N 25
using namespace std;

struct Node {
    int p = -1, l, r;
};
Node T[MAX_N];
int n;

void preParse(int u) {
    if (u == -1) return;
    cout << " " << u;
    preParse(T[u].l);
    preParse(T[u].r);
}

void inParse(int u) {
    if (u == -1) return;
    inParse(T[u].l);
    cout << " " << u;
    inParse(T[u].r);
}

void postParse(int u) {
    if (u == -1) return;
    postParse(T[u].l);
    postParse(T[u].r);
    cout << " " << u;
}

int main() {
    int id, left, right, root;
    cin >> n;
    rep(i, n) {
        cin >> id >> left >> right;
        T[id].l = left;
        T[id].r = right;
        if (left != -1) T[left].p = id;
        if (right != -1) T[right].p = id;
    }
    rep(i, n) {
        if (T[i].p == -1) {
            root = i;
            break;
        }
    }
    cout << "Preorder" << endl;
    preParse(root);
    cout << endl << "Inorder" << endl;
    inParse(root);
    cout << endl << "Postorder" << endl;
    postParse(root);
    cout << endl;
    return 0;
}
