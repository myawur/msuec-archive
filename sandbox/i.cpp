#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    int n, m, a, b;
    cin >> n >> m >> a >> b;

    int cost = min({n * a, n / m * b + n % m * a, (n / m + 1) * b});

    cout << cost << endl;

    return 0;
}