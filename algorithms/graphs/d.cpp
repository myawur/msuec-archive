#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n;

vector<vector<pair<int, int>>> g;
vector<int> d;
vector<int> p;

/**
 * Входные данные: начальная вершина
 * Что делает: реализует алгоритм Дейкстры
 * Выходные данные: void
 */
void dijkstra(int s) {
    vector<bool> u(n, false);

    d[s] = 0;
    for (int i = 0; i < n; i++) {
        int v = -1;
        for (int j = 0; j < n; j++) {
            if (!u[j] && (v == -1 || d[j] < d[v])) {
                v = j;
            }
        }

        if (d[v] == INT_MAX) {
            break;
        }

        u[v] = true;
        for (auto edge : g[v]) {
            int t = edge.first, l = edge.second;
            if (d[v] + l < d[t]) {
                d[t] = d[v] + l;
                p[t] = v;
            }
        }
    }
}

int main() {
    cin >> n;

    g.resize(n, vector<pair<int, int>>(n));
    d.assign(n, INT_MAX);
    p.assign(n, -1);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int u;
            cin >> u;
            if (u != 0) {
                g[i].push_back({j, u});
            }
        }
    }

    int a, b;
    cin >> a >> b;

    dijkstra(a);

    vector<int> path;

    for (int v = b; v != a; v = p[v]) {
        path.push_back(v);
    }
    path.push_back(a);

    reverse(path.begin(), path.end());

    for (int i = 0; i < path.size(); i++) {
        cout << path[i] << ' ';
    }

    return 0;
}