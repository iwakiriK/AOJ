#include <bits/stdc++.h>
using namespace std;

int n, k, w[100000];

bool check(int P) {
    int i = 0;
    for (int j = 0; j < k; j++) {
        int tmp = 0;
        while (tmp + w[i] <= P) {
            tmp += w[i++];
            if (i == n) return true;
        }
    }
    return false;
}

int main() {
    // input
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> w[i];
    // binary search
    int left = 0, right = 1000000000, mid;
    while (right - left > 1) {
        mid = (left + right) / 2;
        if (check(mid)) right = mid;
        else left = mid;
    }
    cout << right << endl;

    return 0;
}
