#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    set<string> S;
    string order, str, out;

    cin >> n;
    while (n--) {
        cin >> order >> str;
        if (order[0] == 'i') S.insert(str);
        else {
            if (S.find(str) == S.end()) out = "no";
            else out = "yes";
            cout << out << endl;
        }
    }
    return 0;
}
