#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int cnt;

void insertionSort(int A[], int n, int g) {
    for (int i = g; i < n; i++) {
        int v = A[i];
        int j = i - g;
        while (j >= 0 && A[j] > v) {
            A[j+g] = A[j];
            j -= g;
            cnt++;
        }
        A[j+g] = v;
    }
}

void shellSort(int A[], int n) {
    // 1, 4, 13, 40, 121, 364, 1093, ...
    vector<int> G;
    int h = 1;
    while (h <= n) {
        G.push_back(h);
        h = 3*h + 1;
    }
    cout << G.size() << endl;
    for (int i = G.size()-1; i >= 0; i--) {
        insertionSort(A, n, G[i]);
        cout << G[i];
        if (i) cout << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    int A[n];
    for (int i = 0; i < n; i++) cin >> A[i];

    shellSort(A, n);

    cout << cnt << endl;
    for (int i = 0; i < n; i++) cout << A[i] << endl;
    return 0;
}
