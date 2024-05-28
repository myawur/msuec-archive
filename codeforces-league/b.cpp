#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    int sum = 0;
    for (int i = 0; i < n; i++) {
        int e;
        cin >> e;
        sum += e;
    }

    sum -= n / 2;
    if (sum > m) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
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