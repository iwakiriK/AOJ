#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, num;
    string com;
    list<int> L;
    cin >> n;
    while (n--) {
        cin >> com;
        if (com.size() > 6) {
            if (com[6] == 'F') L.pop_front();
            else L.pop_back();
        } else {
            cin >> num;
            if (com[0] == 'i') L.push_front(num);
            else {
                for (auto it = L.begin(); it != L.end(); it++) {
                    if (*it == num) {
                        L.erase(it);
                        break;
                    }
                }
            }
        }
    }
    // output
    bool isNotFirst = false;
    for (auto it = L.begin(); it != L.end(); it++) {
        if (isNotFirst) cout << " ";
        cout << *it;
        isNotFirst = true;
    }
    cout << endl;
    return 0;
}
