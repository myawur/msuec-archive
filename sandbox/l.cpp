#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> f(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> f[i];
    }

    bool found = false;
    for (int i = 1; i <= n; i++) {
        if (f[f[f[i]]] == i) {
            found = true;
            break;
        }
    }

    if (found) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
