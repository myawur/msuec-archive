#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> g;
vector<int> color;

/**
 * Входные данные: текущая вершина, цвет
 * Что делает: обход в глубину, в котором окрашиваем граф в два цвета
 * Выходные данные: true, если граф двудольный, иначе false
 */
bool dfs(int v, int c) {
    color[v] = c;
    for (int u : g[v]) {
        if (color[u] == -1) {
            if (!dfs(u, 1 - c)) {
                return false;
            }
        } else if (color[u] == c) {
            return false;
        }
    }
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;

    g.resize(n);
    color.resize(n, -1);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    for (int i = 0; i < n; i++) {
        if (color[i] == -1) {
            if (!dfs(i, 0)) {
                cout << "NO" << endl;
                return 0;
            }
        }
    }

    cout << "YES" << endl;

    return 0;
}