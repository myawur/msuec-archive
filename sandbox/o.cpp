#include <iostream>
#include <set>
#include <unordered_set>
#include <vector>

using namespace std;

void solve() {
    set<int> s;
    for (int i = 0; i < 25; i++) {
        int x;
        cin >> x;
        s.insert(x);
    }

    for (auto &i : s) {
        cout << i << endl;
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