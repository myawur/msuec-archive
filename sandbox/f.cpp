#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, l;
    cin >> n >> l;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    double left = 0, right = l;
    for (int i = 0; i < 100; i++) {
        double mid = (left + right) / 2;
        bool ok = true;
        if (a[0] - mid > 0) ok = false;
        if (a[n - 1] + mid < l) ok = false;
        for (int j = 0; j < n - 1; j++) {
            if (a[j] + mid < a[j + 1] - mid) {
                ok = false;
                break;
            }
        }
        if (ok) right = mid;
        else left = mid;
    }

    cout << fixed << setprecision(10) << right << endl;

    return 0;
}
