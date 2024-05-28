#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int* x = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    for (int i = 0; i <= n / m; i++) {
        for (int j = i * m; j < min(i * m + m, n); j++) {
            if (x[j] >= 0) {
                cout << x[j] << ' ';
            }
        }

        for (int j = i * m; j < min(i * m + m, n); j++) {
            if (x[j] < 0) {
                cout << x[j] << ' ';
            }
        }

        cout << endl;
    }

    delete[] x;

    return 0;
}
