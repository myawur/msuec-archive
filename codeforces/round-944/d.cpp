#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long ll;
typedef unsigned long long ull;

void solve() {
    string s;
    cin >> s;

    string a = s;
    sort(a.begin(), a.end());
    if (a == s) {
        cout << '1' << endl;
        return;
    }

    int count = 0;
    size_t pos;
    while ((pos = s.find("01")) != string::npos) {
        s.erase(pos, 2);
    }

    cout << s.size() << endl;
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
