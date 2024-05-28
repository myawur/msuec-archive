#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> parts(2 * n);
    for (int i = 0; i < 2 * n; i++) {
        cin >> parts[i];
    }

    sort(parts.begin(), parts.end());
    for (int i = 0; i < n; i++) {
        cout << parts[i] << ' ' << parts[2 * n - 1 - i] << endl;
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