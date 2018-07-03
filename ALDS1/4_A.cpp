#include <bits/stdc++.h>
using namespace std;

int n, S[1000000], q, key, ans;

bool linearSearch() {
    S[n] = key;
    int i = 0;
    while (S[i] != key) i++;
    if (i == n) return false;
    return true;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> S[i];
    cin >> q;
    while (q--) {
        cin >> key;
        if (linearSearch()) ans++;
    }
    cout << ans << endl;
    return 0;
}
