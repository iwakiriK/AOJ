#include <bits/stdc++.h>
using namespace std;

int main() {
    string str;
    stack<int> S;
    while (cin >> str) {
        if (str[0] < '0' || str[0] > '9') {
            int b = S.top(); S.pop();
            int a = S.top(); S.pop();
            if (str[0] == '+') {
                S.push(a + b);
            } else if (str[0] == '-') {
                S.push(a - b);
            } else {
                S.push(a * b);
            }
        } else {
            S.push(atoi(str.c_str()));
        }
    }
    cout << S.top() << endl;
    
    return 0;
}
