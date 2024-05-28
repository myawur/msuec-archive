/**
 * ЮФУ, ИКТИБ, МОП ЭВМ
 * Структуры и алгоритмы обработки данных
 * Лабораторная работа №1
 * Задание A
 * Исполнитель: Кожемякин Ярослав Дмитриевич (КТбо1-7)
 * 02.03.2024
 */

#include <iostream>
#include <list>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    list<int> pos, neg;

    int count = 0;
    for (int i = 0; i < n; i++) {
        count++;

        int number;
        cin >> number;

        if (number >= 0) pos.push_back(number);
        else neg.push_back(number);

        if (count >= m || i >= n - 1) {
            count = 0;

            while (pos.size() > 0) {
                cout << pos.front() << ' ';
                pos.pop_front();
            }
            while (neg.size() > 0) {
                cout << neg.front() << ' ';
                neg.pop_front();
            }

            cout << endl;
        }
    }

    return 0;
}
