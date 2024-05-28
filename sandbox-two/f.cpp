#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());
    if (v.back() - v[0] <= 1) {
        cout << n << endl;
        for (int i = 0; i < v.size(); i++) {
            cout << v[i] << ' ';
        }
        return;
    }

    int l = v[0], r = v.back(), m = l + 1;
    int x = 0, y = 0, z = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] == l) {
            x++;
        }
        if (v[i] == r) {
            y++;
        }
        if (v[i] == m) {
            z++;
        }
    }

    int a = min(x, y), b = z / 2;
    if (a >= b) {
        cout << n - 2 * a << endl;

        for (int i = 0; i < x - a; i++) {
            cout << l << ' ';
        }
        for (int i = 0; i < y - a; i++) {
            cout << r << ' ';
        }
        for (int i = 0; i < n - x - y + 2 * a; i++) {
            cout << m << ' ';
        }
    } else {
        cout << n - 2 * b << endl;

        for (int i = 0; i < x + b; i++) {
            cout << l << ' ';
        }
        for (int i = 0; i < y + b; i++) {
            cout << r << ' ';
        }
        for (int i = 0; i < n - x - y - 2 * b; i++) {
            cout << m << ' ';
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