#include <bits/stdc++.h>
using namespace std;

int N, A[1000];

void print() {
    for (int i = 0; i < N; i++) {
        if (i) cout << " ";
        cout << A[i];
    }
    cout << endl;
}

int main() {
    // input
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    // Insertion Sort
    for (int i = 0; i < N; i++) {
        int v = A[i];
        int j = i - 1;
        while (j >= 0 && A[j] > v) {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = v;
        print();
    }
    return 0;
}
