/**
 * Movie Festival
 * https://cses.fi/problemset/task/1629
 */

#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long ll;
typedef unsigned long long ull;

void solve() {
    int n;
    cin >> n;

    vector<pair<int, int>> v(n);
    for (auto& i : v) {
        cin >> i.first >> i.second;
    }
    sort(v.begin(), v.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
    });

    int last_end = -1, count = 0;
    for (const auto& i : v) {
        if (i.first >= last_end) {
            last_end = i.second;
            count++;
        }
    }

    cout << count << endl;
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
