#include <bits/stdc++.h>
using namespace std;

int n, num;
int minv = INT_MAX, maxv = INT_MIN;

int main() {
    cin >> n;
    while(n--) {
        cin >> num;
        maxv = max(maxv, num - minv);
        minv = min(minv, num);
    }
    cout << maxv << endl;
    return 0;
}