#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> dx = {1, -1, 0, 0};
vector<int> dy = {0, 0, 1, -1};
vector<char> dm = {'D', 'U', 'R', 'L'};

vector<vector<pair<char, int>>> grid;

vector<char> path;

int n, m;

bool is_available(int i, int j) {
    return i >= 0 && i < n && j >= 0 && j < m;
}

bool dfs(int i, int j, char c) {
    if (grid[i][j].second == 1) {
        path.push_back(c);
        return true;
    }

    if (grid[i][j].second == 2) {
        return false;
    }

    grid[i][j].second = 1;
    for (int k = 0; k < 4; k++) {
        int nx = i + dx[k];
        int ny = j + dy[k];

        if (c == 'R' && dm[k] == 'L') {
            continue;
        }
        if (c == 'L' && dm[k] == 'R') {
            continue;
        }
        if (c == 'U' && dm[k] == 'D') {
            continue;
        }
        if (c == 'D' && dm[k] == 'U') {
            continue;
        }

        if (is_available(nx, ny)) {
            if (grid[nx][ny].first != '.') {
                dfs(nx, ny, dm[k]);
            }
        }
    }

    path.push_back(c);

    grid[i][j].second = true;
    grid[i][j].first = 2;

    return false;
}

void solve() {
    cin >> n >> m;
    grid.resize(n, vector<pair<char, int>>(m, make_pair('.', 0)));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j].first;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j].first == 'S') {
                dfs(i, j, 'Q');
            }
        }
    }

    reverse(path.begin(), path.end());

    for (int i = 2; i < path.size(); i++) {
        cout << path[i];
    }
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