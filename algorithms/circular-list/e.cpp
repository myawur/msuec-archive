/**
 * ЮФУ, ИКТИБ, МОП ЭВМ
 * Структуры и алгоритмы обработки данных
 * Домашнее задание №1.2
 * Задание E
 * Исполнитель: Кожемякин Ярослав Дмитриевич (КТбо1-7)
 * 20.02.2024
 */

#include <iostream>

using namespace std;

/**
 * Структура элемента списка
 */
typedef struct Item {
    int value;
    Item* next;
}* List;

/**
 * Входные данные: значение элемента
 * Что делает: создает новые элемент списка
 * Выходные данные: новый элемент списка
 */
List CreateItem(int value) {
    List item = new Item;

    item->value = value;
    item->next = item;

    return item;
}

/**
 * Входные данные: указатель на голову списка
 * Что делает: добавляет элемент в голову списка
 * Выходные данные: ничего
 */
void Push(List& head, int value) {
    List item = CreateItem(value);

    if (head == nullptr) {
        head = item;
    } else {
        List temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = item;
        item->next = head;
    }
}

/**
 * Входные данные: указатель на голову список, указатель на элемент
 * Что делает: удаляет определенный элемент из списка
 * Выходные данные: ничего
 */
void Pop(List& head, List& item) {
    if (head == item) head = item->next;

    List temp = head;
    while (temp->next != item) {
        temp = temp->next;
    }

    temp->next = item->next;

    delete item;
}

/**
 * Входные данные: указатель на голову списка
 * Что делает: проверяет, пуст ли список
 * Выходные данные: true, если стек пуст, иначе false
 */
bool Empty(List& top) {
    return top == nullptr;
}

int main() {
    int n, k;
    cin >> n >> k;

    List head = nullptr;

    for (int i = 0; i < n; i++) {
        Push(head, i + 1);
    }

    List current = head;
    while (n--) {
        for (int i = 0; i < k - 1; i++) {
            current = current->next;
        }

        cout << current->value << " ";

        List next_item = current->next;
        Pop(head, current);
        current = next_item;
    }

    return 0;
}