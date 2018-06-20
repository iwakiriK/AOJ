#include <bits/stdc++.h>
using namespace std;

int n, num;
int Min = 2000000000, ans = -Min;

int main() {
    cin >> n;
    while(n--) {
        cin >> num;
        ans = max(ans, num - Min);
        Min = min(Min, num);
    }
    cout << ans << endl;
    return 0;
}