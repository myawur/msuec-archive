/**
 * ЮФУ, ИКТИБ, МОП ЭВМ
 * Структуры и алгоритмы обработки данных
 * Лабораторная работа №3
 * Задание A
 * Исполнитель: Кожемякин Ярослав Дмитриевич (КТбо1-7)
 * 30.03.2024
 */

#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> x(n);
    set<int> u;

    for (auto &e : x) {
        cin >> e;

        if (!u.count(e)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }

        u.insert(e);
    }

    return 0;
}
