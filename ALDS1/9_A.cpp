#include <bits/stdc++.h>
#define REP(i,a,b) for(int i=(a);i<(b);++i)
#define MAX_H 250
using namespace std;

int main() {
    int H, A[MAX_H+1];
    cin >> H;
    REP(i, 1, H+1) cin >> A[i];
    REP(i, 1, H+1) {
        cout << "node " << i << ": key = " << A[i] << ", ";
        if (i/2 >= 1) cout << "parent key = " << A[i/2] << ", ";
        if (2*i <= H) cout << "left key = " << A[2*i] << ", ";
        if (2*i+1 <= H) cout << "right key = " << A[2*i+1] << ", ";
        cout << endl;
    }
    return 0;
}
