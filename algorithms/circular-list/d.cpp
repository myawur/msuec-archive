/**
 * ЮФУ, ИКТИБ, МОП ЭВМ
 * Структуры и алгоритмы обработки данных
 * Домашнее задание №1.2
 * Задание D
 * Исполнитель: Кожемякин Ярослав Дмитриевич (КТбо1-7)
 * 20.02.2024
 */

#include <iostream>
#include <string>

using namespace std;

/**
 * Структура элемента стека
 */
typedef struct Item {
    int value;
    Item* next;
}* Stack;

/**
 * Входные данные: указатель на вершину стека, значение элемента
 * Что делает: добавляет элемент в вершину стека
 * Выходные данные: ничего
 */
void Push(Stack& top, int value) {
    Stack item = new Item;

    item->value = value;
    item->next = top;

    top = item;
}

/**
 * Входные данные: указатель на вершину стека
 * Что делает: удаляет элемент из вершины стека
 * Выходные данные: значение удаленного элемента
 */
int Pop(Stack& top) {
    Stack item = top;

    int value = item->value;
    top = top->next;

    return value;
}

/**
 * Входные данные: указатель на вершину стека
 * Что делает: получает значение элемента из вершины стека
 * Выходные данные: значение элемента из вершины стека5
 */
int Top(Stack& top) {
    return top->value;
}

/**
 * Входные данные: указатель на вершину стека
 * Что делает: проверяет, пуст ли стек
 * Выходные данные: true, если стек пуст, иначе false
 */
bool Empty(Stack& top) {
    return top == nullptr;
}

int main() {
    string sequence;
    getline(cin, sequence);

    Stack top = nullptr;

    for (int i = 0; i < sequence.size(); i++) {
        char element = sequence[i];

        if (element > 47) {
            Push(top, element - 48);
        } else if (element > 32) {
            int first = Pop(top), second = Pop(top);

            switch (element) {
                case '+':
                    Push(top, first + second);
                    break;
                case '-':
                    Push(top, second - first);
                    break;
                case '*':
                    Push(top, first * second);
                    break;
                default:
                    break;
            }
        }
    }

    cout << Top(top) << endl;

    return 0;
}
