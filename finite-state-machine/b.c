/**
 * ЮФУ, ИКТИБ, МОП ЭВМ
 * Программирование и основы теории алгоритмов
 * Домашнее задание №1
 * Проектирование и реализация конечного распознавателя
 * Исполнитель: Кожемякин Ярослав Дмитриевич (КТбо1-7)
 * 16.03.2024
 */

#include <stdio.h>

#define kInputLength 100
#define kAnwserLength 4
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

void InitializeTable(int table[kNumberStates][kNumberInputs]) {
    table[0][0] = 1123;
}

int main() {
    TransitionTable table;

    InitializeTable(table.transitions);

    printf("%d\n", table.transitions[0][0]);

    // for (int state = 0; state < kNumberStates; state++) {
    //     for (int digit = 0; digit < kNumberInputs; digit++) {
    //         table.transitions[state][digit] = (state * 3 + digit) % 11;
    //     }
    // }

    // for (int i = 0; i < kNumberStates; i++) {
    //     for (int j = 0; j < kNumberInputs; j++) {
    //         printf("%d ", table.transitions[i][j]);
    //     }
    //     printf("\n");
    // }

    return 0;
}
