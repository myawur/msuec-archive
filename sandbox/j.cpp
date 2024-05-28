#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int q;
    cin >> q;

    while (q--) {
        int n;
        cin >> n;
        vector<int> a(4 * n);
        for (int i = 0; i < 4 * n; i++) {
            cin >> a[i];
        }

        sort(a.begin(), a.end());

        bool possible = true;
        int area = a[0] * a[4 * n - 1];
        for (int i = 0; i < n; i++) {
            int j = 4 * n - 1 - i;
            if (a[2 * i] != a[2 * i + 1] || a[j * 2] != a[j * 2 + 1] || a[2 * i] * a[j * 2] != area) {
                possible = false;
                break;
            }
        }

        if (possible) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}