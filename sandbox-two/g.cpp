#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> h(n + 1, 0);
    h[0] = 1;

    int result = 0;

    vector<int> count(n + 1, 0);
    count[0] = 1;
    for (int i = 1; i < n; i++) {
        int a;
        cin >> a;
        a--;
        h[i] = h[a] + 1;
        count[h[i]]++;
    }

    for (int i = 0; i <= n; i++) {
        if (count[i] % 2 != 0) {
            result++;
        }
    }

    cout << result;
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