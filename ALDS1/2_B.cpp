#include <bits/stdc++.h>
using namespace std;

int N, A[1000], ans;

int main() {
    // input
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    // Selection Sort
    for (int i = 0; i < N; i++) {
        int minj = i;
        for (int j = i; j < N; j++) {
            if (A[j] < A[minj]) minj = j;
        }
        if (A[i] != A[minj]) ans++;
        swap(A[i], A[minj]);
    }
    // output
    for (int i = 0; i < N; i++) {
        if (i) cout << " ";
        cout << A[i];
    }
    cout << endl << ans << endl;
    return 0;
}
