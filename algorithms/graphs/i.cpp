/**
 * ЮФУ, ИКТИБ, МОП ЭВМ
 * Структуры и алгоритмы обработки данных
 * Домашнее задание №5.3
 * Задание I
 * Кожемякин Ярослав Дмитриевич (КТбо1-7)
 * 03.05.2024
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int n, s;
vector<vector<int>> g;
vector<int> match;
vector<bool> used;

/**
 * Входные данные: вершина
 * Что делает: ищет увеличивающую цепь через алгоритм Куна
 * Выходные данные: есть цепь или нет
 */
bool dfs(int v) {
    if (used[v]) {
        return false;
    }
    used[v] = true;

    for (int i = 0; i < n; i++) {
        if (g[v][i] && (match[i] == -1 || dfs(match[i]))) {
            match[i] = v;
            return true;
        }
    }

    return false;
}

/**
 * Входные данные: void
 * Что делает: решает задачу
 * Выходные данные: void
 */
void solve() {
    cin >> n >> s;

    g.resize(s, vector<int>(n));
    match.assign(n, -1);

    for (int i = 0; i < s; i++) {
        for (int j = 0; j < n; j++) {
            cin >> g[i][j];
        }
    }

    for (int i = 0; i < s; i++) {
        used.assign(s, false);
        dfs(i);
    }

    int result = 0;
    for (int i = 0; i < n; i++) {
        if (match[i] != -1) {
            result++;
        }
    }

    cout << result << endl;
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
