/**
 * ЮФУ, ИКТИБ, МОП ЭВМ
 * Структуры и алгоритмы обработки данных
 * Домашнее задание №5.3
 * Задание G
 * Кожемякин Ярослав Дмитриевич (КТбо1-7)
 * 03.05.2024
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Edge {
    int u, v, weight;
    bool operator<(Edge const& other) {
        return weight < other.weight;
    }
};

/**
 * Входные данные: void
 * Что делает: реализует алгоритм Краскала
 * Выходные данные: вес минимального остовного дерева
 */
void solve() {
    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
        edges[i].u--;
        edges[i].v--;
    }

    int total_weight = 0;
    vector<int> tree_id(n);
    vector<Edge> result;
    for (int i = 0; i < n; i++) {
        tree_id[i] = i;
    }

    sort(edges.begin(), edges.end());

    for (Edge e : edges) {
        if (tree_id[e.u] != tree_id[e.v]) {
            total_weight += e.weight;
            result.push_back(e);

            int old_id = tree_id[e.u], new_id = tree_id[e.v];
            for (int i = 0; i < n; i++) {
                if (tree_id[i] == old_id) {
                    tree_id[i] = new_id;
                }
            }
        }
    }

    cout << total_weight << endl;
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
