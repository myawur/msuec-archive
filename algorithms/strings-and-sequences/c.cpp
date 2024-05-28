/**
 * ЮФУ, ИКТИБ, МОП ЭВМ
 * Структуры и алгоритмы обработки данных
 * Домашнее задание №6.1
 * Задание C
 * Кожемякин Ярослав Дмитриевич (КТбо1-7)
 * 06.05.2024
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
    bool first_red = false;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'R' && !first_red) {
            first_red = true;
        }
        if (s[i] == 'B' && first_red) {
            s.erase(i, 1);
            i--;
            count++;
        }
    }

    cout << s << endl;
    cout << count << endl;
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