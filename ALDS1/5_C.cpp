#include <bits/stdc++.h>
using namespace std;

struct Point { double x, y; };

void koch(int n, Point a, Point b) {
    if (n == 0) return;
    Point s, t, u;
    s.x = (2*a.x + b.x) / 3;
    s.y = (2*a.y + b.y) / 3;
    t.x = (a.x + 2*b.x) / 3;
    t.y = (a.y + 2*b.y) / 3;
    double th = M_PI / 3.0; // 60 degrees
    u.x = (t.x - s.x) * cos(th) - (t.y - s.y) * sin(th) + s.x;
    u.y = (t.x - s.x) * sin(th) + (t.y - s.y) * cos(th) + s.y;

    koch(n - 1, a, s);
    cout << s.x << " " << s.y << endl;
    koch(n - 1, s, u);
    cout << u.x << " " << u.y << endl;
    koch(n - 1, u, t);
    cout << t.x << " " << t.y << endl;
    koch(n - 1, t, b);
}

int main() {
    int n;
    cin >> n;

    Point a, b;
    a.x = 0, a.y = 0;
    b.x = 100, b.y = 0;
    cout << a.x << " " << a.y << endl;
    koch(n, a, b);
    cout << b.x << " " << b.y << endl;

    return 0;
}
