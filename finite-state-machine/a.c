/**
 * ЮФУ, ИКТИБ, МОП ЭВМ
 * Программирование и основы теории алгоритмов
 * Домашнее задание №1
 * Проектирование и реализация конечного распознавателя
 * Исполнитель: Кожемякин Ярослав Дмитриевич (КТбо1-7)
 * 16.03.2024
 */

#define _CRT_SECURE_NO_WARNINGS

#include <locale.h>
#include <stdio.h>
#include <string.h>
#include <wchar.h>
#include <windows.h>

#define kInputLength 512
#define kAnwserLength 16
#define kNumberStates 11
#define kNumberInputs 3

/**
 * Структура данных, реализующая таблицу переходов для конечного автомата.
 */
typedef struct {
    /**
     * kNumberStates - количество состояний конечного автомата.
     * KNumberInputs - количество входных символов.
     */
    int transitions[kNumberStates][kNumberInputs];
} TransitionTable;

/**
 * Входные данные: wchar_t* input - строка, содержащая число в троичной системе счисления.
 * Что делает: проверяет, есть ли в строке символы, отличные от 0, 1 и 2.
 * Выходные данные: 1, если строка содержит только символы 0, 1 и 2, иначе 0.
 */
int IsValidAlphabet(wchar_t*);

/**
 * Входные данные: wchar_t* answer - строка, в который находится ответ пользователя.
 * Что делает: проверяет, является ли строка ответом на вопрос.
 * Выходные данные: 1, если строка является ответом на вопрос, иначе 0.
 */
int IsValidAnswer(wchar_t*);

/**
 * Входные данные: цифра из троичного числа, текущее состояние автомата, таблица переходов.
 * Что делает: возвращает новое состояние автомата.
 * Выходные данные: обновленное состояние.
 */
int ChangeState(int, int, int[kNumberStates][kNumberInputs]);

/**
 * Входные данные: пустая таблица переходов.
 * Что делает: заполняет таблицу переходов.
 * Выходные данные: заполненная таблица переходов.
 */
void InitializeTable(int[kNumberStates][kNumberInputs]);

int main() {
    setlocale(LC_ALL, "Russian");

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    wchar_t input[kInputLength];

    int algorithm_state = 0;

    TransitionTable table;

    InitializeTable(table.transitions);

    while (algorithm_state < 2) {
        do {
            wprintf(L"Введите число в троичной системе счисления (или 'стоп', чтобы выйти из программы): ");
            wscanf(L"%ls", input);

            if (!wcscmp(input, L"стоп")) {
                wprintf(L"Программа завершена.\n");
                algorithm_state = 2;
            } else {
                if (!IsValidAlphabet(input)) {
                    wprintf(L"Введённое число не является троичным.\n");
                } else {
                    algorithm_state = 1;
                }
            }
        } while (algorithm_state < 1);

        if (algorithm_state != 2) {
            int state = 0;
            int input_length = wcslen(input);

            for (int i = 0; i < input_length; i++) {
                int digit = input[i] - '0';

                int previous_state = state;
                state = ChangeState(digit, state, table.transitions);

                wprintf(L"%d: q%d -> q%d", digit, previous_state, state);

                if (i + 1 >= input_length) {
                    wprintf(L" - ");
                } else {
                    wprintf(L"\n");
                }
            }

            if (state != 0) {
                printf("Yes\n");
            } else {
                printf("No\n");
            }

            wchar_t answer[kAnwserLength];

            do {
                wprintf(L"Хотите ввести еще одно число? (да/нет): ");

                wscanf(L"%ls", answer);

                if (!IsValidAnswer(answer)) {
                    wprintf(L"Неправильный ответ, повторите снова.\n");
                } else {
                    if (!wcscmp(answer, L"да")) {
                        algorithm_state = 0;
                    } else {
                        wprintf(L"Программа завершена.\n");
                        algorithm_state = 2;
                    }
                }
            } while (!IsValidAnswer(answer));
        }
    }

    return 0;
}

int IsValidAlphabet(wchar_t* input) {
    for (int i = 0; i < wcslen(input); i++) {
        int digit = input[i] - '0';

        if (digit < 0 || digit > 2) {
            return 0;
        }
    }

    return 1;
}

int IsValidAnswer(wchar_t* answer) {
    return (!wcscmp(answer, L"да") || !wcscmp(answer, L"нет"));
}

int ChangeState(int digit, int state, int table[kNumberStates][kNumberInputs]) {
    return table[state][digit];
}

void InitializeTable(int table[kNumberStates][kNumberInputs]) {
    int values[11][3] = {
        {0, 1, 2},
        {3, 4, 5},
        {6, 7, 8},
        {9, 10, 0},
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
        {10, 0, 1},
        {2, 3, 4},
        {5, 6, 7},
        {8, 9, 10}};

    for (int i = 0; i < kNumberStates; i++) {
        for (int j = 0; j < kNumberInputs; j++) {
            table[i][j] = values[i][j];
        }
    }
}
