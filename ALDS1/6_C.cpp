#include <bits/stdc++.h>
#define REP(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n) REP(i,0,n)
using namespace std;

struct Card {
    char suit;
    int value;
};

Card A[100000], B[100000];
int n;

void merge(int left, int mid, int right) {
    int n1 = mid - left;
    int n2 = right - mid;
    Card L[n1+1], R[n2+1];
    rep(i, n1) L[i] = A[left+i];
    rep(i, n2) R[i] = A[mid+i];
    L[n1].value = R[n2].value = INT_MAX;
    int i = 0, j = 0;
    REP(k, left, right) {
        if (L[i].value <= R[j].value) {
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

int partition(int p, int r) {
    int x = B[r].value;
    int i = p - 1;
    REP(j, p, r) {
        if (B[j].value <= x) {
            swap(B[++i], B[j]);
        }
    }
    swap(B[++i], B[r]);
    return i;
}

void quickSort(int p, int r) {
    if (p < r) {
        int q = partition(p, r);
        quickSort(p, q - 1);
        quickSort(q + 1, r);
    }
}

int main() {
    // input
    cin >> n;
    rep(i, n) {
        cin >> A[i].suit >> A[i].value;
        B[i].suit = A[i].suit;
        B[i].value = A[i].value;
    }
    // sort
    mergeSort(0, n);
    quickSort(0, n - 1);
    string str = "Stable";
    rep(i, n) {
        if (A[i].suit != B[i].suit) str = "Not stable";
    }
    // output
    cout << str << endl;
    rep(i, n) cout << B[i].suit << " " << B[i].value << endl;

    return 0;
}
