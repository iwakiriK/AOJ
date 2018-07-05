#include <bits/stdc++.h>
#define REP(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n) REP(i,0,n)
using namespace std;

int cnt = 0, n, A[500000];

void merge(int left, int mid, int right) {
    int n1 = mid - left;
    int n2 = right - mid;
    int L[n1+1], R[n2+1];
    rep(i, n1) L[i] = A[left+i];
    rep(i, n2) R[i] = A[mid+i];
    L[n1] = R[n2] = INT_MAX;
    int i = 0, j = 0;
    REP(k, left, right) {
        cnt++;
        if (L[i] <= R[j]) {
            A[k] = L[i++];
        } else {
            A[k] = R[j++];
        }
    }
}

void mergeSort(int left, int right) {
    if (left + 1 < right) {
        int mid = (left + right) / 2;
        mergeSort(left, mid);
        mergeSort(mid, right);
        merge(left, mid, right);
    }
}

int main() {
    cin >> n;
    rep(i, n) cin >> A[i];

    mergeSort(0, n);

    rep(i, n) {
        if (i) cout << " ";
        cout << A[i];
    }
    cout << endl << cnt << endl;

    return 0;
}
