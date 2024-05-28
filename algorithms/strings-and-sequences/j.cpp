/**
 * ЮФУ, ИКТИБ, МОП ЭВМ
 * Структуры и алгоритмы обработки данных
 * Лабораторная работа №7
 * Задание D
 * Кожемякин Ярослав Дмитриевич (КТбо1-7)
 * 25.05.2024
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/**
 * Входные данные: void
 * Что делает: решает задачу
 * Выходные данные: void
 */
void solve() {
    string s;
    cin >> s;

    int min_length = s.size() + 1;
    vector<int> count(3);

    int l = 0, r = 0;
    while (r < s.size()) {
        int index = s[r] - '0';
        index--;
        count[index]++;
        r++;
        while (count[0] > 0 && count[1] > 0 && count[2] > 0) {
            min_length = min(min_length, r - l);

            int index = s[l] - '0';
            index--;
            count[index]--;
            l++;
        }
    }

    if (min_length == s.size() + 1) {
        cout << 0 << endl;
    } else {
        cout << min_length << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}