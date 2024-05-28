/**
 * ЮФУ, ИКТИБ, МОП ЭВМ
 * Программирование и основы теории алгоритмов
 * Домашнее задание №2
 * Реализация и анализ примитивно-рекурсивной функции
 * Кожемякин Ярослав Дмитриевич (КТбо1-7)
 * 10.04.2024
 */

#include <clocale>
#include <iostream>
#include <string>

using namespace std;

/**
 * Входные данные: строка
 * Что делает: проверяет, является ли строка ответом на вопрос
 * Выходные данные: 1, если строка является ответом на вопрос, иначе 0
 */
bool IsValidAnswer(string);

/**
 * Входные данные: x1 и x2
 * Что делает: проверяет, являются ли числа неотрицательными
 * Выходные данные: 1, если числа неотрицательные, иначе 0
 */
bool IsValidInput(int, int);

/**
 * Входные данные: y и x
 * Что делает: вычисляет значение примитивно-рекурсивной функции
 * Выходные данные: значение примитивно-рекурсивной функции
 */
int Calculate(int, int);

int main() {
    setlocale(LC_ALL, "Russian");

    bool is_active = true;

    /**
     * g(x) = x^2
     * h(x, y, z) = z * y
     *
     * f(0, x) = g(x) = x^2
     * f(y + 1, x) = h(y, f(y, x), x) = x * f(y, x)
     */
    cout << "Заданные функции: " << endl;
    cout << "g(x) = x^2" << endl;
    cout << "h(x, y, z) = z * y" << endl;
    cout << endl;

    cout << "Схема рекурсии: " << endl;
    cout << "f(0, x) = g(x) = x^2" << endl;
    cout << "f(y + 1, x) = h(y, f(y, x), x) = x * f(y, x)" << endl;
    cout << endl;

    while (is_active) {
        int x1, x2;
        do {
            cout << "Введите значения x1 и x2: ";
            cin >> x1 >> x2;

            if (!IsValidInput(x1, x2)) {
                cout << "Неправильный ввод, повторите снова." << endl;
            }
        } while (!IsValidInput(x1, x2));

        Calculate(x1, x2);

        string answer;
        do {
            cout << "Хотите продолжить? (да/нет): ";
            cin >> answer;

            if (!IsValidAnswer(answer)) {
                cout << "Неправильный ответ, повторите снова." << endl;
            } else if (answer == "нет" || answer == "net") {
                is_active = false;
            }
        } while (!IsValidAnswer(answer));
    }

    return 0;
}

bool IsValidAnswer(string answer) {
    return answer == "да" || answer == "нет" || answer == "da" || answer == "net";
}

bool IsValidInput(int x1, int x2) {
    return x1 >= 0 && x2 >= 0;
}

int Calculate(int y, int x) {
    int result;

    if (y == 0) {
        result = x * x;

        cout << "f(0, x) = g(x) = ";
        cout << x << "^2 = ";
        cout << result << endl;
    } else {
        int previous = Calculate(y - 1, x);

        result = x * previous;

        cout << "f(" << y << ", " << x << ") = ";
        cout << "h(" << y << ", f(" << y - 1 << ", " << x << "), " << x << ") = ";
        cout << x << " * " << previous << " = ";
        cout << result << endl;
    }

    return result;
}