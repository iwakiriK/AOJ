#include <bits/stdc++.h>
#define REP(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n) REP(i,0,n)
using namespace std;

int n, A[100000];

int partition(int p, int r) {
    int x = A[r];
    int i = p-1;
    REP(j, p, r) {
        if (A[j] <= x) {
            swap(A[++i], A[j]);
        }
    }
    swap(A[i+1], A[r]);
    return i + 1;
}

int main() {
    cin >> n;
    rep(i, n) cin >> A[i];

    int q = partition(0, n-1);

    rep(i, n) {
        if (i) cout << " ";
        if (i != q) cout << A[i];
        else cout << "[" << A[i] << "]";
    }
    cout << endl;
    
    return 0;
}
