#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q, time;
    string name;
    queue<pair<string, int> >Q;
    cin >> n >> q;
    while (n--) {
        cin >> name >> time;
        Q.push(make_pair(name, time));
    }

    pair<string, int> pr;
    int t, ans = 0;
    while (!Q.empty()) {
        pr = Q.front(); Q.pop();
        t = min(pr.second, q);
        pr.second -= t;
        ans += t;
        if (pr.second > 0) {
            Q.push(pr);
        } else {
            cout << pr.first << " " << ans << endl;
        }
    }
    return 0;
}
