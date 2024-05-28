/**
 * ЮФУ, ИКТИБ, МОП ЭВМ
 * Структуры и алгоритмы обработки данных
 * Домашнее задание №6.2
 * Задание E
 * Кожемякин Ярослав Дмитриевич (КТбо1-7)
 * 18.05.2024
 */

#include <algorithm>
#include <deque>
#include <iostream>
#include <vector>

using namespace std;

/**
 * Входные данные: void
 * Что делает: решает задачу
 * Выходные данные: void
 */
void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    deque<int> d;
    for (int i = 0; i < n; i++) {
        while (!d.empty() && d.front() <= i - k) {
            d.pop_front();
        }

        while (!d.empty() && v[d.back()] >= v[i]) {
            d.pop_back();
        }
        d.push_back(i);

        if (i >= k - 1) {
            cout << v[d.front()] << endl;
        }
    }
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