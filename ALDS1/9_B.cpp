#include <bits/stdc++.h>
#define REP(i,a,b) for(int i=(a);i<(b);++i)
#define rrep(i,n) for(int i=(n);i>0;--i)
#define MAX_H 500000
using namespace std;

int H, A[MAX_H+1];

void maxHeapify(int i) {
    int l = 2 * i;
    int r = 2 * i + 1;
    int largest = i;
    if (l <= H && A[l] > A[i]) largest = l;
    if (r <= H && A[r] > A[largest]) largest = r;
    if (largest != i) {
        swap(A[i], A[largest]);
        maxHeapify(largest);
    }
}

int main() {
    cin >> H;
    REP(i, 1, H+1) cin >> A[i];
    rrep(i, H/2) maxHeapify(i);
    REP(i, 1, H+1) cout << " " << A[i];
    cout << endl;
    return 0;
}
