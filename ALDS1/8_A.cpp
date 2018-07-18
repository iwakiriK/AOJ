#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);++i)
using namespace std;

struct Node {
    int key;
    Node *p, *left, *right;
};
Node *root, *NIL;

void insert(int k) {
    Node *y = NIL;
    Node *x = root;
    while (x != NIL) {
        y = x;
        if (k < x->key) {
            x = x->left;
        } else {
            x = x->right;
        }
    }
    Node *z = new Node;
    z->key = k;
    z->p = y;
    z->left = NIL;
    z->right = NIL;
    if (y == NIL) {
        root = z;
    } else {
        if (z->key < y->key) {
            y->left = z;
        } else {
            y->right = z;
        }
    }
}

void inorder(Node *u) {
    if (u == NIL) return;
    inorder(u->left);
    cout << " " << u->key;
    inorder(u->right);
}
void preorder(Node *u) {
    if (u == NIL) return;
    cout << " " << u->key;
    preorder(u->left);
    preorder(u->right);
}


int main() {
    int n, k;
    string com;
    cin >> n;
    rep (i, n) {
        cin >> com;
        if (com[0] == 'i') {
            cin >> k;
            insert(k);
        } else {
            inorder(root);
            cout << endl;
            preorder(root);
            cout << endl;
        }
    }
    
    return 0;
}
