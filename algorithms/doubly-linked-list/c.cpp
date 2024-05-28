/**
 * ЮФУ, ИКТИБ, МОП ЭВМ
 * Структуры и алгоритмы обработки данных
 * Домашнее задание №1.1
 * Задание C
 * Исполнитель: Кожемякин Ярослав Дмитриевич (КТбо1-7)
 * 16.02.2024
 */

#include <iostream>
#include <string>

using namespace std;

/**
 * Структура элемента двусвязного списка
 */
typedef struct Item {
    char value;
    Item* next;
    Item* prev;
}* List;

/**
 * Входные данные: указатели на конец начало/конец списка, значение элемента
 * Что делает: добавляет элемент в начало списка
 * Выходные данные: ничего
 */
void PushFront(List& head, List& tail, char value) {
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
void PushBack(List& head, List& tail, char value) {
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
char PopFront(List& head, List& tail) {
    if (head == nullptr)
        return '\0';
    List front = head;
    char value = front->value;
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
char PopBack(List& head, List& tail) {
    if (tail == nullptr)
        return '\0';
    List back = tail;
    char value = back->value;
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

/**
 * Входные данные: строка
 * Что делает: проверяет, правильная ли последовательность
 * Выходные данные: true, если правильная, иначе false
 */
bool IsCorrectSequence(string sequence) {
    List head = nullptr;
    List tail = nullptr;

    for (char c : sequence) {
        if (c == '(' || c == '[' || c == '{') {
            PushBack(head, tail, c);
        } else {
            char last_open = PopBack(head, tail);
            if ((c == ')' && last_open != '(') ||
                (c == ']' && last_open != '[') ||
                (c == '}' && last_open != '{')) {
                return false;
            }
        }
    }
    return Empty(head);
}

int main() {
    string s;
    cin >> s;

    if (IsCorrectSequence(s)) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }

    return 0;
}
