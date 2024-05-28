/**
 * ЮФУ, ИКТИБ, МОП ЭВМ
 * Структуры и алгоритмы обработки данных
 * Домашнее задание №1.1
 * Задание A
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
    List first_head = nullptr;
    List first_tail = nullptr;
    List second_head = nullptr;
    List second_tail = nullptr;

    for (int i = 0; i < 5; i++) {
        int a;
        cin >> a;
        PushFront(first_head, first_tail, a);
    }

    for (int i = 0; i < 5; i++) {
        int a;
        cin >> a;
        PushFront(second_head, second_tail, a);
    }

    int count = 0;
    while (!Empty(first_head) && !Empty(second_head) && count < 1e6) {
        int a = PopBack(first_head, first_tail);
        int b = PopBack(second_head, second_tail);

        if (a == 0 && b == 9) {
            PushFront(first_head, first_tail, a);
            PushFront(first_head, first_tail, b);
        } else if (a == 9 && b == 0) {
            PushFront(second_head, second_tail, a);
            PushFront(second_head, second_tail, b);
        } else if (a > b) {
            PushFront(first_head, first_tail, a);
            PushFront(first_head, first_tail, b);
        } else {
            PushFront(second_head, second_tail, a);
            PushFront(second_head, second_tail, b);
        }

        count++;
    }

    if (Empty(first_head)) {
        cout << "second " << count;
    } else if (Empty(second_head)) {
        cout << "first " << count;
    } else {
        cout << "botva";
    }

    return 0;
}