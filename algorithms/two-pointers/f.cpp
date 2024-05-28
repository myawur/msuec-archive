/**
 * ЮФУ, ИКТИБ, МОП ЭВМ
 * Структуры и алгоритмы обработки данных
 * Домашнее задание №6.2
 * Задание F
 * Кожемякин Ярослав Дмитриевич (КТбо1-7)
 * 18.05.2024
 */

#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

/**
 * Входные данные: void
 * Что делает: решает задачу
 * Выходные данные: void
 */
void solve() {
    int n, m;
    cin >> n;
    vector<int> shirts(n);
    for (int i = 0; i < n; i++) {
        cin >> shirts[i];
    }

    cin >> m;
    vector<int> pants(m);
    for (int i = 0; i < m; i++) {
        cin >> pants[i];
    }

    int min_diff = INT_MAX;
    pair<int, int> result;
    for (int i = 0; i < n; i++) {
        int pos = lower_bound(pants.begin(), pants.end(), shirts[i]) - pants.begin();
        if (pos < m) {
            int diff = abs(shirts[i] - pants[pos]);
            if (diff < min_diff) {
                min_diff = diff;
                result = {shirts[i], pants[pos]};
            }
        }
        if (pos > 0) {
            int diff = abs(shirts[i] - pants[pos - 1]);
            if (diff < min_diff) {
                min_diff = diff;
                result = {shirts[i], pants[pos - 1]};
            }
        }
    }

    cout << result.first << " " << result.second << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}