#include <iostream>

using namespace std;

int main() {
    int n, k, m;
    cin >> n >> k >> m;

    int* a = new int[n];
    for (int i = 0; i < n; i++) {
        a[i] = i + 1;
    }

    int j = 0, s = n;
    for (int i = 0; i < m; i++) {
        j = (j + k - 1) % s;
        for (int l = j; l < s - 1; l++) {
            a[l] = a[l + 1];
        }
        s--;
    }

    for (int i = 0; i < s; i++) {
        cout << a[i] << ' ';
    }

    delete[] a;

    return 0;
}
