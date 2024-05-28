/**
 * ЮФУ, ИКТИБ, МОП ЭВМ
 * Структуры и алгоритмы обработки данных
 * Лабораторная работа №7
 * Задание A
 * Кожемякин Ярослав Дмитриевич (КТбо1-7)
 * 25.05.2024
 */

#include <iostream>

using namespace std;

/**
 * Входные данные: void
 * Что делает: решает задачу
 * Выходные данные: void
 */
void solve() {
    string s;
    cin >> s;

    int count = 0;
    for (char c : s) {
        if (c == 'B' && count > 0) {
            count--;
        } else {
            count++;
        }
    }

    cout << count << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
