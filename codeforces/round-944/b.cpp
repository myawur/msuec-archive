#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long ll;
typedef unsigned long long ull;

void solve() {
    string s;
    cin >> s;

    set<char> c(s.begin(), s.end());
    if (c.size() <= 1) {
        cout << "NO" << endl;
        return;
    }

    next_permutation(s.begin(), s.end());
    cout << "YES" << endl;
    cout << s << endl;
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
