/**
 * ЮФУ, ИКТИБ, МОП ЭВМ
 * Структуры и алгоритмы обработки данных
 * Лабораторная работа №2
 * Задание A
 * Исполнитель: Кожемякин Ярослав Дмитриевич (КТбо1-7)
 * 16.03.2024
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/**
 * Входные данные: число
 * Что делает: считает сумму цифр числа
 * Выходные данные: сумма цифр числа
 */
int DigitSum(int n) {
    int sum = 0;
    while (n) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

/**
 * Входные данные: два числа
 * Что делает: сравнивает сумму цифр чисел
 * Выходные данные: true или false
 */
bool Compare(int a, int b) {
    int sum1 = DigitSum(a);
    int sum2 = DigitSum(b);
    if (sum1 == sum2) {
        return a < b;
    }
    return sum1 < sum2;
}

int main() {
    int n;
    cin >> n;

    vector<int> a(n);

    for (auto& e : a) {
        cin >> e;
    }

    sort(a.begin(), a.end(), Compare);

    for (const auto& e : a) {
        cout << e << ' ';
    }

    return 0;
}
