#include <bits/stdc++.h>
#define REP(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n) REP(i,0,n)
#define MAX_N 1000
#define MAX_wi 10000
typedef long long ll;
using namespace std;

int n, w[MAX_N], ans, sorted_w[MAX_N];
int Min = MAX_wi, correct_position[MAX_wi+1];
bool isUsed[MAX_N];

int main() {
    cin >> n;
    rep(i, n) {
        cin >> w[i];
        Min = min(Min, w[i]);
    }
    // examine the correct position
    rep(i, n) sorted_w[i] = w[i];
    sort(sorted_w, sorted_w + n);
    rep(i, n) correct_position[sorted_w[i]] = i;
    // calculate minimum cost of cycle
    rep(i, n) {
        if (isUsed[i]) continue;
        int idx = i, cnt = 0, local_min = MAX_wi, sum = 0;
        while (true) {
            isUsed[idx] = true;
            cnt++;
            int num = w[idx];
            local_min = min(local_min, num);
            sum += num;
            idx = correct_position[num];
            if (isUsed[idx]) break;
        }
        ans += min(sum+(cnt-2)*local_min, local_min+sum+(cnt+1)*Min);
    }

    cout << ans << endl;

    return 0;
}
