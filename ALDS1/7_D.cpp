#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;

int n, idx;
vector<int> pre, in, post;

void reconstruction(int l, int r) {
    if (l >= r) return;
    int root = pre[idx++];
    int root_idx = distance(in.begin(), find(in.begin(), in.end(), root));
    reconstruction(l, root_idx);
    reconstruction(root_idx+1, r);
    post.push_back(root);
}

int main() {
    cin >> n;
    int id;
    rep(i, n) {
        cin >> id;
        pre.push_back(id);
    }
    rep(i, n) {
        cin >> id;
        in.push_back(id);
    }
    reconstruction(0, n);

    rep(i, n) {
        if (i) cout << " ";
        cout << post[i];
    }
    cout << endl;
    return 0;
}