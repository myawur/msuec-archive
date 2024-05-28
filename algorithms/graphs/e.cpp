#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

vector<vector<pair<int, int>>> g;
vector<int> d;

const int kInfNumber = 1e9;

/**
 * Входные данные: начальная вершина
 * Что делает: реализует алгоритм Дейкстры
 * Выходные данные: void
 */
void dijkstra(int s) {
    d.assign(g.size(), kInfNumber);
    d[s] = 0;

    set<pair<int, int>> q;
    q.insert({0, s});

    while (!q.empty()) {
        int v = q.begin()->second;
        q.erase(q.begin());

        for (auto edge : g[v]) {
            int to = edge.first;
            int len = edge.second;

            if (d[v] + len < d[to]) {
                q.erase({d[to], to});
                d[to] = d[v] + len;
                q.insert({d[to], to});
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    g.resize(n);
    d.resize(n);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;

        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    int max_distance = 0;
    for (int i = 0; i < n; i++) {
        dijkstra(i);
        for (int j = 0; j < n; j++) {
            if (d[j] != kInfNumber) {
                max_distance = max(max_distance, d[j]);
            }
        }
    }

    cout << max_distance << endl;

    return 0;
}