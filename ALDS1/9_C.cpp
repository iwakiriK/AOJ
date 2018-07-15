#include <bits/stdc++.h>
#define REP(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n) REP(i,0,n)
typedef long long ll;
using namespace std;

int main() {
    priority_queue<int> PQ;
    int k;
    string com;
    while (true) {
        cin >> com;
        if (com[0] == 'i') {
            cin >> k;
            PQ.push(k);
        } else if (com[1] == 'x') {
            cout << PQ.top() << endl;
            PQ.pop();
        } else {
            break;
        }
    }
    return 0;
}
