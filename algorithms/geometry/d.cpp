/**
 * ЮФУ, ИКТИБ, МОП ЭВМ
 * Структуры и алгоритмы обработки данных
 * Домашнее задание №7
 * Задание D
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
    int x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    int x4, y4;
    if ((x2 - x1) * (x3 - x1) + (y2 - y1) * (y3 - y1) == 0) {
        x4 = x1 + (x2 - x1) + (x3 - x1);
        y4 = y1 + (y2 - y1) + (y3 - y1);
    } else if ((x1 - x2) * (x3 - x2) + (y1 - y2) * (y3 - y2) == 0) {
        x4 = x2 + (x1 - x2) + (x3 - x2);
        y4 = y2 + (y1 - y2) + (y3 - y2);
    } else if ((x1 - x3) * (x2 - x3) + (y1 - y3) * (y2 - y3) == 0) {
        x4 = x3 + (x1 - x3) + (x2 - x3);
        y4 = y3 + (y1 - y3) + (y2 - y3);
    }

    cout << x4 << ' ' << y4 << endl;
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