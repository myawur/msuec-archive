/**
 * ЮФУ, ИКТИБ, МОП ЭВМ
 * Структуры и алгоритмы обработки данных
 * Лабораторная работа №2
 * Задание B
 * Исполнитель: Кожемякин Ярослав Дмитриевич (КТбо1-7)
 * 16.03.2024
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);

    for (auto& e : a) {
        cin >> e;
    }

    sort(a.begin(), a.end());

    int m;
    cin >> m;

    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;

        int amount = lower_bound(a.begin(), a.end(), x) - a.begin();
        cout << amount << endl;
    }

    return 0;
}
