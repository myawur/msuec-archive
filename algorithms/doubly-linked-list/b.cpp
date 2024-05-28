/**
 * ЮФУ, ИКТИБ, МОП ЭВМ
 * Структуры и алгоритмы обработки данных
 * Домашнее задание №1.1
 * Задание B
 * Исполнитель: Кожемякин Ярослав Дмитриевич (КТбо1-7)
 * 16.02.2024
 */

#include <iostream>

using namespace std;

/**
 * Структура элемента двусвязного списка
 */
typedef struct Item {
    int value;
    Item* next;
    Item* prev;
}* List;

/**
 * Входные данные: указатели на конец начало/конец списка, значение элемента
 * Что делает: добавляет элемент в начало списка
 * Выходные данные: ничего
 */
void PushFront(List& head, List& tail, int value) {
    List front = new Item;
    front->value = value;
    front->next = head;
    front->prev = nullptr;
    if (head != nullptr) {
        head->prev = front;
    }
    head = front;
    if (tail == nullptr) {
        tail = front;
    }
}

/**
 * Входные данные: указатели на конец начало/конец списка, значение элемента
 * Что делает: добавляет элемент в конец списка
 * Выходные данные: ничего
 */
void PushBack(List& head, List& tail, int value) {
    List back = new Item;
    back->value = value;
    back->next = nullptr;
    back->prev = tail;
    if (tail != nullptr) {
        tail->next = back;
    }
    tail = back;
    if (head == nullptr) {
        head = back;
    }
}

/**
 * Входные данные: указатель на начало/конец списка
 * Что делает: удаляет элемент из начала списка
 * Выходные данные: значение удаленного элемента
 */
int PopFront(List& head, List& tail) {
    if (head == nullptr)
        return -1;
    List front = head;
    int value = front->value;
    head = front->next;
    if (head != nullptr)
        head->prev = nullptr;
    else
        tail = nullptr;
    delete front;
    return value;
}

/**
 * Входные данные: указатель на начало/конец списка
 * Что делает: удаляет элемент из конца списка
 * Выходные данные: значение удаленного элемента
 */
int PopBack(List& head, List& tail) {
    if (tail == nullptr)
        return -1;
    List back = tail;
    int value = back->value;
    tail = back->prev;
    if (tail != nullptr)
        tail->next = nullptr;
    else
        head = nullptr;
    delete back;
    return value;
}

/**
 * Входные данные: указатель на начало списка
 * Что делает: проверяет, пуст ли список
 * Выходные данные: true, если список пуст, иначе false
 */
bool Empty(List head) {
    return head == nullptr;
}

int main() {
    int n;
    cin >> n;

    List shelf_head = nullptr;
    List shelf_tail = nullptr;
    List results_head = nullptr;
    List results_tail = nullptr;

    for (int i = 0; i < n; i++) {
        int operation;
        cin >> operation;
        if (operation == 1) {
            int value;
            cin >> value;
            PushFront(shelf_head, shelf_tail, value);
        } else if (operation == 2) {
            int value;
            cin >> value;
            PushBack(shelf_head, shelf_tail, value);
        } else if (operation == 3) {
            PushBack(results_head, results_tail, PopFront(shelf_head, shelf_tail));
        } else if (operation == 4) {
            PushBack(results_head, results_tail, PopBack(shelf_head, shelf_tail));
        }
    }

    while (results_head != nullptr) {
        cout << PopFront(results_head, results_tail) << endl;
    }

    return 0;
}
