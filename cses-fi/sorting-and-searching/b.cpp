/**
 * Apartments
 * https://cses.fi/problemset/task/1084
 */

#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long ll;
typedef unsigned long long ull;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(n);
    for (auto &i : a) {
        cin >> i;
    }

    vector<int> b(m);
    for (auto &i : b) {
        cin >> i;
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int count = 0;
    int i = 0, j = 0;
    while (i < n) {
        while (j < m && b[j] < a[i] - k) {
            j++;
        }
        if (abs(b[j] - a[i]) <= k) {
            count++;
            i++;
            j++;
        } else {
            i++;
        }
    }

    cout << count << endl;
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
