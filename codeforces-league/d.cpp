#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
    string s;
    cin >> s;

    ll index = 0;
    for (char c : s) {
        index = index * 26 + (c - 'A' + 1);
    }

    cout << index << endl;
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