#include <bits/stdc++.h>
using namespace std;

int n, q, A[20], m;
set<int> S;

void subsetSum(int idx, int num) {
    if (idx == n) S.insert(num);
    else {
        subsetSum(idx+1, num);
        subsetSum(idx+1, num+A[idx]);
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> A[i];
    subsetSum(0, 0);
    cin >> q;
    while (q--) {
        cin >> m;
        if (S.find(m) == S.end()) cout << "no" << endl;
        else cout << "yes" << endl;
    }
    return 0;
}
