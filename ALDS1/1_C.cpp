#include <bits/stdc++.h>
using namespace std;

int n, num, ans;

bool isPrime (int x) {
    if (x == 2) return true;
    if (x < 2 || x % 2 == 0) return false;
    for (int i = 3; i <= sqrt(x); i += 2) {
        if (x % i == 0) return false;
    }
    return true;
}

int main() {
    cin >> n;
    while (n--) {
        cin >> num;
        if (isPrime(num)) ans++;
    }
    cout << ans << endl;
    return 0;
}
