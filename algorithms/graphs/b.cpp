#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> g;
vector<bool> used;

/**
 * Входные данные: номер вершины
 * Что делает: находит все ребра у вершины и переходит к следующим вершинам
 * Выходные данные: void, заполняет вектор visited
 */
void dfs(int v) {
    used[v] = true;

    for (int i = 0; i < g[v].size(); i++) {
        if (g[v][i] && !used[i]) {
            dfs(i);
        }
    }
}

int main() {
    int n;
    cin >> n;

    g.resize(n, vector<int>(n));
    used.resize(n, false);

    int edges = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> g[i][j];
            edges += g[i][j];
        }
    }

    dfs(0);

    for (int i = 0; i < n; i++) {
        // cout << visited[i] << endl;
        if (!used[i]) {
            cout << "NO" << endl;
            return 0;
        }
    }

    if (edges == (n - 1) * 2) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
