#include <bits/stdc++.h>
#define REP(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n) REP(i,0,n)
typedef long long ll;
using namespace std;

const int MAX_N = 2000000, MAX_Ai = 10000;
int n, A[MAX_N], C[MAX_Ai+1], B[MAX_N];

int main() {
    cin >> n;
    rep(i, n) {
        cin >> A[i];
        C[A[i]]++;
    }
    rep(i, MAX_Ai) {
        C[i+1] += C[i];
    }
    rep(i, n) {
        B[C[A[i]]-1] = A[i];
        C[A[i]]--;
    }
    rep(i, n) {
        if (i) cout << " ";
        cout << B[i];
    }
    cout << endl;
    return 0;
}
