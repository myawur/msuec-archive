#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

vector<vector<pair<int, int>>> g;
vector<int> d;
vector<int> students;

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
    int n;
    cin >> n;

    g.resize(n);
    d.resize(n);
    students.resize(n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;

            if (i != j && x != 0) {
                g[i].push_back({j, x});
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cin >> students[i];
    }

    int min_distance = kInfNumber;
    int v = -1;
    for (int i = 0; i < n; i++) {
        dijkstra(i);

        int total_distance = 0;

        for (int j = 0; j < n; j++) {
            total_distance += d[j] != kInfNumber ? d[j] * students[j] : 10000 * students[j];
        }

        if (total_distance < min_distance) {
            min_distance = total_distance;
            v = i;
        }
    }

    cout << v + 1 << ' ' << min_distance << endl;

    return 0;
}
