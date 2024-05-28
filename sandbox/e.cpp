#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n), b(n - 1), c(n - 2);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; i++) {
        cin >> b[i];
    }
    for (int i = 0; i < n - 2; i++) {
        cin >> c[i];
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());

    for (int i = 0; i < n; i++) {
        if (i == n - 1 || a[i] != b[i]) {
            cout << a[i] << endl;
            break;
        }
    }

    for (int i = 0; i < n - 1; i++) {
        if (i == n - 2 || b[i] != c[i]) {
            cout << b[i] << endl;
            break;
        }
    }

    return 0;
}
