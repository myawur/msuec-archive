/**
 * Restaurant Customers
 * https://cses.fi/problemset/task/1619
 */

#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long ll;
typedef unsigned long long ull;

void solve() {
    int n;
    cin >> n;

    map<int, int> m;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        m[a]++;
        m[b]--;
    }

    int sum = 0, max_sum = 0;
    for (const auto &i : m) {
        sum += i.second;
        max_sum = max(sum, max_sum);
    }

    cout << max_sum << endl;
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
