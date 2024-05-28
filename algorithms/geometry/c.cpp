/**
 * ЮФУ, ИКТИБ, МОП ЭВМ
 * Структуры и алгоритмы обработки данных
 * Домашнее задание №7
 * Задание C
 * Кожемякин Ярослав Дмитриевич (КТбо1-7)
 * 23.05.2024
 */

#include <bits/stdc++.h>

using namespace std;

/**
 * Входные данные: void
 * Что делает: решает задачу
 * Выходные данные: void
 */
void solve() {
    double r, x, y;
    cin >> r >> x >> y;
    x = abs(x);

    cout << fixed << setprecision(2) << (r * x) / (2 * r - y) << endl;
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