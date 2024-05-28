#include <iostream>
#include <vector>

using namespace std;

int main() {
    int q;
    cin >> q;

    while (q--) {
        int n, k;
        cin >> n >> k;

        vector<int> a(n + 1);

        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }

        vector<int> odd_indices;
        for (int i = 1; i <= n; i++) {
            if (a[i] % 2 != 0) {
                odd_indices.push_back(i);
            }
        }

        if (odd_indices.size() < k || (odd_indices.size() - k) % 2 == 1) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;

            for (int i = 0; i < k - 1; i++) {
                cout << odd_indices[i] << " ";
            }

            cout << n << endl;
        }
    }

    return 0;
}