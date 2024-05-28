#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int& e : a) {
        cin >> e;
    }

    vector<int> v(n + 1);
    for (int& e : a) {
        v[e]++;
    }

    int count = 0;
    int l = 0, r = n - 1;
    while (l < r) {
        if (a[l] == a[r]) {
            v[a[l]] -= 2;
            l++;
            r--;
        } else if (v[a[l]] > v[a[r]]) {
            v[a[l]]--;
            l++;
            count++;
        } else {
            v[a[r]]--;
            r--;
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