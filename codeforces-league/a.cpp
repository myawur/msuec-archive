#include <bits/stdc++.h>

using namespace std;

void solve() {
    map<string, int> days;
    days["Monday"] = 5;
    days["Tuesday"] = 4;
    days["Wednesday"] = 3;
    days["Thursday"] = 2;
    days["Friday"] = 1;

    string input_day;
    cin >> input_day;

    cout << days[input_day] << endl;
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