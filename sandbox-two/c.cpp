#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    vector<int> b(m);
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    sort(b.begin(), b.end());

    for (int i = 0; i < n; i++) {
        if (find(b.begin(), b.end(), a[i]) != b.end()) {
            cout << a[i] << endl;
            return;
        }
    }

    cout << min(a[0], b[0]) << max(a[0], b[0]) << endl;
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