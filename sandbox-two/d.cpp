#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n, a, b;
    cin >> n >> a >> b;

    int round = 0;
    while (n > 1) {
        round++;
        a = (a + 1) / 2;
        b = (b + 1) / 2;
        if (a == b) {
            break;
        }
        n /= 2;
    }

    if (n == 2) {
        cout << "Final!" << endl;
    } else {
        cout << round << endl;
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