#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;

int main() {
    string t, p;
    cin >> t >> p;
    int n = t.size() - p.size() + 1;
    rep(i, n) {
        bool isSame = true;
        rep(j, p.size()) {
            if (t[i+j] != p[j]) {
                isSame = false;
                break;
            }
        }
        if (isSame) cout << i << endl;
    }
    
    return 0;
}
