#include <bits/stdc++.h>
#define REP(i,a,b) for(int i=(a);i<(b);++i)
#define MAX_N 44
using namespace std;

int main() {
    int n, F[MAX_N+1];
    F[0] = F[1] = 1;
    cin >> n;
    REP(i, 2, n+1) F[i] = F[i-1] + F[i-2];
    cout << F[n] << endl;
    return 0;
}
