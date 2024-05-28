/**
 * ЮФУ, ИКТИБ, МОП ЭВМ
 * Структуры и алгоритмы обработки данных
 * Домашнее задание №2.1
 * Задание B
 * Исполнитель: Кожемякин Ярослав Дмитриевич (КТбо1-7)
 * 27.02.2024
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> numbers(n);

    for (auto &number : numbers) {
        cin >> number;
    }

    vector<int> sorted_numbers = numbers;
    sort(sorted_numbers.begin(), sorted_numbers.end());

    int left = 0, right = n - 1;
    for (int i = 0; i < n; i++) {
        if (i % 2 != 0) numbers[right--] = sorted_numbers[i];
        else numbers[left++] = sorted_numbers[i];
    }

    for (const auto &number : numbers) {
        cout << number << ' ';
    }

    return 0;
}
