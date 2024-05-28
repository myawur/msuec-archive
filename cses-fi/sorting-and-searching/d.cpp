/**
 * Concert Tickets
 * https://cses.fi/problemset/task/1091
 */

#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long ll;
typedef unsigned long long ull;

void solve() {
    int n, m;
    cin >> n >> m;

    multiset<int> h;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        h.insert(x);
    }

    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;

        auto a = h.upper_bound(x);
        if (a != h.begin()) {
            a--;
            cout << *a << endl;
            h.erase(a);
        } else {
            cout << "-1" << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
