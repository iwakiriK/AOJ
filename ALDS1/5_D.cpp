#include <bits/stdc++.h>
#define REP(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n) REP(i,0,n)
#define MAX_N 200000
typedef long long ll;
using namespace std;

int n, A[MAX_N], L[MAX_N/2 + 2], R[MAX_N/2 + 2];
ll ans;

void merge(int left, int mid, int right) {
    int n1 = mid - left;
    int n2 = right - mid;
    rep(i, n1) L[i] = A[left+i];
    rep(i, n2) R[i] = A[mid+i];
    L[n1] = R[n2] = INT_MAX;
    int i = 0, j = 0;
    REP(k, left, right) {
        if (L[i] <= R[j]) {
            A[k] = L[i++];
        } else {
            A[k] = R[j++];
            ans += n1 - i;
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
    cout << ans << endl;
    return 0;
}
