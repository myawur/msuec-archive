/**
 * Ferris Wheel
 * https://cses.fi/problemset/task/1090
 */

#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long ll;
typedef unsigned long long ull;

void solve() {
    int n, x;
    cin >> n >> x;

    vector<int> p(n);
    for (auto &i : p) {
        cin >> i;
    }

    sort(p.begin(), p.end());

    int count = 0;
    int l = 0, r = p.size() - 1;
    while (l < r) {
        int sum = p[l] + p[r];
        if (sum <= x) {
            count++;
            l++;
            r--;
        } else if (p[r] <= x) {
            count++;
            r--;
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
