#include <cmath>
#include <iostream>

using namespace std;

typedef long long ll;

int main() {
    ll n, m;
    cin >> n >> m;

    ll min_isolated = max(0ll, n - 2 * m);
    ll max_isolated = n;

    for (ll i = 0; i <= n; i++) {
        if (i * (i - 1) / 2 >= m) {
            max_isolated = min(max_isolated, n - i);
            break;
        }
    }

    cout << min_isolated << " " << max_isolated << endl;

    return 0;
}
