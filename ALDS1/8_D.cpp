#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);++i)
using namespace std;

struct Node {
    int key, priority;
    Node *left, *right;
};
Node *root, *NIL;
Node *Delete(Node *, int);
Node *_delete(Node *, int);

Node *rightRotate(Node *t) {
    Node *s = t->left;
    t->left = s->right;
    s->right = t;
    return s;
}

Node *leftRotate(Node *t) {
    Node *s = t->right;
    t->right = s->left;
    s->left = t;
    return s;
}

Node *Delete(Node *t, int key) {
    if (t == NIL) return NIL;
    if (key < t->key) {
        t->left = Delete(t->left, key);
    } else if (key > t->key) {
        t->right = Delete(t->right, key);
    } else {
        return _delete(t, key);
    }
    return t;
}

Node *_delete(Node *t, int key) {
    if (t->left == NIL && t->right == NIL) {
        return NIL;
    } else if (t->left == NIL) {
        t = leftRotate(t);
    } else if (t->right == NIL) {
        t = rightRotate(t);
    } else {
        if (t->left->priority > t->right->priority) {
            t = rightRotate(t);
        } else {
            t = leftRotate(t);
        }
    }
    return Delete(t, key);
}

Node* find(int k) {
    Node *u = root;
    while (u != NIL && u->key != k) {
        if (k < u->key) u = u->left;
        else u = u->right;
    }
    return u;
}

Node *insert(Node *t, int key, int priority) {
    if (t == NIL) {
        t = new Node;
        t->left = NIL; t->right = NIL;
        t->key = key; t->priority = priority;
        return t;
    }

    if (key == t->key) return t;

    if (key < t->key) {
        t->left = insert(t->left, key, priority);
        if (t->priority < t->left->priority) {
            t = rightRotate(t);
        }
    } else {
        t->right = insert(t->right, key, priority);
        if (t->priority < t->right->priority) {
            t = leftRotate(t);
        }
    }
    return t;
}

Node *treeSuccessor(Node *x) {
    x = x->right;
    while (x->left != NIL) {
        x = x->left;
    }
    return x;
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
    int n, k, p;
    string com;
    cin >> n;
    rep (i, n) {
        cin >> com;
        if (com[0] == 'i') {
            cin >> k >> p;
            root = insert(root, k, p);
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
            root = Delete(root, k);
        }
    }
    return 0;
}
