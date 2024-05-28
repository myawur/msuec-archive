#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int* a = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int m;
    cin >> m;

    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;

        int l = 1, r = n;
        while (l < r) {
            int mid = (l + r) / 2;
            if (x > a[mid]) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }

        if (x <= a[l - 1]) {
            l--;
        }

        cout << l << endl;
    }

    delete[] a;
    
    return 0;
}
