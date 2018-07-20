#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);++i)
using namespace std;

struct Node {
    int key;
    Node *p, *left, *right;
};
Node *root, *NIL;

Node* find(int k) {
    Node *u = root;
    while (u != NIL && u->key != k) {
        if (k < u->key) u = u->left;
        else u = u->right;
    }
    return u;
}

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

Node *treeSuccessor(Node *x) {
    x = x->right;
    while (x->left != NIL) {
        x = x->left;
    }
    return x;
}

void treeDelete(Node *z) {
    int child = 0;
    if (z->left != NIL) child++;
    if (z->right != NIL) child++;
    Node *y; // delete
    Node *x; // y's child
    // decide y
    if (z->left == NIL || z->right == NIL) y = z;
    else y = treeSuccessor(z);
    // decide x
    if (y->left != NIL) x = y->left;
    else x = y->right; // may be NIL
    if (x != NIL) x->p = y->p;
    // update y's parent
    if (y->p == NIL) {
        root = x;
    } else {
        if (y == y->p->left) {
            y->p->left = x;   
        } else {
            y->p->right = x; // may be NIL
        }
    }

    if (y != z) z->key = y->key;

    delete y;
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
        } else if (com[0] == 'p'){
            inorder(root);
            cout << endl;
            preorder(root);
            cout << endl;
        } else if (com[0] == 'f'){
            cin >> k;
            Node *t = find(k);
            if (t != NIL) cout << "yes" << endl;
            else cout << "no" << endl;
        } else {
            cin >> k;
            treeDelete(find(k));
        }
    }
    return 0;
}
