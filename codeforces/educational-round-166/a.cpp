#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long ll;
typedef unsigned long long ull;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    string a = s;
    sort(a.begin(), a.end());
    if (a != s) {
        cout << "NO" << endl;
        return;
    }

    bool prev_letter = false;
    for (char c : s) {
        if (!isalnum(c)) {
            cout << "NO" << endl;
            return;
        }

        if (isalpha(c)) {
            prev_letter = true;
        } else {
            prev_letter = false;
        }

        if (isdigit(c) && prev_letter) {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
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
