#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long ll;
typedef unsigned long long ull;

void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    if (a < b) {
        swap(a, b);
    }
    if (c < d) {
        swap(c, d);
    }

    if ((a >= c && a >= d && b <= c && b >= d) || (c >= a && c >= b && d <= a && d >= b)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
