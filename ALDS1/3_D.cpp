#include <bits/stdc++.h>
using namespace std;

int main() {
    stack<int> S1; // total area
    stack<pair<int, int> >S2; // area of each puddle
    char ch;
    int sum = 0;
    for (int i = 0; cin >> ch; i++) {
        if (ch == '\\') S1.push(i);
        else if (ch == '/' && S1.size() > 0) {
            int j = S1.top(); S1.pop();
            int area = i - j;
            sum += area;
            // update S2
            while (S2.size() > 0 && S2.top().first > j) {
                area += S2.top().second; S2.pop();
            }
            S2.push(make_pair(j, area));
        }
    }
    //output
    cout << sum << endl;
    vector<int> ans;
    while (S2.size() > 0) {
        ans.push_back(S2.top().second); S2.pop();
    }
    cout << ans.size();
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++) {
        cout << " " << ans[i];
    }
    cout << endl;
    return 0;
}
