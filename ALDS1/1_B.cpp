#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int x, y;

int gcd(int x, int y) {
    if (x < y) swap(x, y);
    while (y > 0) {
        int r = x % y;
        x = y;
        y = r;
    }
    return x;
}

int main() {
    cin >> x >> y;
    cout << gcd(x, y) << endl;
    return 0;
}
