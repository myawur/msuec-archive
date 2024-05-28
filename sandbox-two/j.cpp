#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;

    if (n < 4) {
        cout << -1 << endl;
    } else if (n % 4 == 0 || n % 4 == 2) {
        cout << n / 4 << endl;
    } else {
        if (n % 4 == 1) {
            if (n >= 9) {
                cout << (n / 4 - 1) << endl;
            } else {
                cout << -1 << endl;
            }
        } else if (n % 4 == 2) {
            cout << n / 4 << endl;
        } else if (n % 4 == 3) {
            if (n >= 15) {
                cout << (n / 4 - 1) << endl;
            } else {
                cout << -1 << endl;
            }
        }
    }
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
