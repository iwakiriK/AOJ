#include <bits/stdc++.h>
using namespace std;

int n, S[1000000], q, key, ans;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> S[i];
    cin >> q;
    while (q--) {
        cin >> key;
        if (*lower_bound(S, S + n, key) == key) ans++;
    }
    cout << ans << endl;
    return 0;
}
