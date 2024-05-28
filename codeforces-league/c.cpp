#include <bits/stdc++.h>

using namespace std;

void solve() {
    string x;
    cin >> x;

    int n = x.size();
    int count = 0;
    for (int i = 0; i < n - 1; i++) {
        if (x[i] == '0' && x[i + 1] == '0') {
            count++;
            i++;
        }
    }

    int result = n - count;
    cout << result << endl;
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