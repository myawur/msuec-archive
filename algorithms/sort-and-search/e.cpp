/**
 * ЮФУ, ИКТИБ, МОП ЭВМ
 * Структуры и алгоритмы обработки данных
 * Лабораторная работа №1
 * Задание B
 * Исполнитель: Кожемякин Ярослав Дмитриевич (КТбо1-7)
 * 02.03.2024
 */

#include <iostream>
#include <stack>

using namespace std;

int main() {
    int n;
    cin >> n;

    stack<int> numbers;
    stack<int> max_numbers;

    for (int i = 0; i < n; i++) {
        string task;
        cin >> task;

        if (task == "PUSH") {
            int number;
            cin >> number;

            numbers.push(number);

            if (max_numbers.empty() || number > max_numbers.top()) {
                max_numbers.push(number);
            } else {
                max_numbers.push(max_numbers.top());
            }
        } else if (task == "POP") {
            numbers.pop();
            max_numbers.pop();
        } else {
            cout << max_numbers.top() << endl;
        }
    }

    return 0;
}