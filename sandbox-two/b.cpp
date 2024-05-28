#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);

    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    vector<int> heights(m, 0);
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; ++i) {
            if (grid[i][j] == '*') {
                heights[j] = n - i;
                break;
            }
        }
    }

    int max_ascent = 0, max_descent = 0;
    for (int j = 1; j < m; j++) {
        int change = heights[j] - heights[j - 1];
        if (change > 0) {
            max_ascent = max(max_ascent, change);
        } else {
            max_descent = max(max_descent, -change);
        }
    }

    cout << max_ascent << ' ' << max_descent << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}