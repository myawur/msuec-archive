/**
 * ЮФУ, ИКТИБ, МОП ЭВМ
 * Структуры и алгоритмы обработки данных
 * Домашнее задание №2.2
 * Задание D
 * Исполнитель: Кожемякин Ярослав Дмитриевич (КТбо1-7)
 * 27.02.2024
 */

#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> numbers(n);
    map<int, int> count;

    for (auto &number : numbers) {
        cin >> number;
        count[number]++;
    }

    for (int i = 0; i < n; i++) {
        int total = 0;
        for (int j = 0; j < n; j++) {
            int a = numbers[i], b = numbers[j];

            if (i != j && a > b && count.count(a - b)) {
                total += count[a - b];
                if (a - b == b) total--;
            }
        }
        cout << total / 2 << endl;
    }

    return 0;
}
