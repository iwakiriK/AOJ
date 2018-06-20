#include <bits/stdc++.h>
using namespace std;

int N, A[1000], ans;

int main() {
    // input
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    // Bubble Sort
    bool flag = true;
    while (flag) {
        flag = false;
        for (int j = N-1; j > 0; j--) {
            if (A[j] < A[j-1]) {
                swap(A[j], A[j-1]);
                flag = true;
                ans++;
            }
        }
    }
    // output
    for (int i = 0; i < N; i++) {
        if (i) cout << " ";
        cout << A[i];
    }
    cout << endl << ans << endl;
    return 0;
}
