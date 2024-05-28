#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long ll;
typedef unsigned long long ull;

void solve() {
    int n;
    cin >> n;

    vector<ll> s(n), t(n), result(n);
    for (ll &e : s) {
        cin >> e;
    }
    for (ll &e : t) {
        cin >> e;
    }

    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    for (int i = 0; i < n; ++i) {
        pq.push({t[i], i});
    }

    while (!pq.empty()) {
        ll time = pq.top().first;
        int i = pq.top().second;
        pq.pop();

        if (result[i] == 0) {
            result[i] = time;
            pq.push({time + s[i], (i + 1) % n});
        }
    }

    for (ll &r : result) {
        cout << r << endl;
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