#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> g;
vector<bool> used;

/**
 * Входные данные: текущая вершина
 * Что делает: обход в глубину
 * Выходные данные: void, изменяет вектор visited
 */
void dfs(int v) {
    used[v] = true;

    for (int u : g[v]) {
        if (!used[u]) {
            dfs(u);
        }
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    k--;

    g.resize(n);
    used.resize(n);

    int x, y;
    while (cin >> x, x) {
        cin >> y;
        x--;
        y--;

        g[x].push_back(y);
    }

    dfs(k);

    for (bool v : used) {
        if (!v) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;

    return 0;
}
