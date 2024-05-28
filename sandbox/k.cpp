#include <iostream>

using namespace std;

typedef long long ll;

int main() {
    int t;
    cin >> t;

    while (t--) {
        ll n, k;
        cin >> n >> k;

        ll result = k / (n - 1) * n + k % (n - 1);

        if (k % (n - 1) == 0) result--;
        cout << result << endl;
    }

    return 0;
}