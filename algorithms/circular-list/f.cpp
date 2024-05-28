/**
 * ЮФУ, ИКТИБ, МОП ЭВМ
 * Структуры и алгоритмы обработки данных
 * Домашнее задание №1.2
 * Задание F
 * Исполнитель: Кожемякин Ярослав Дмитриевич (КТбо1-7)
 * 20.02.2024
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

    if (head != nullptr) head->prev = front;

    head = front;

    if (tail == nullptr) tail = front;
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

    if (tail != nullptr) tail->next = back;

    tail = back;

    if (head == nullptr) head = back;
}

/**
 * Входные данные: указатель на начало/конец списка
 * Что делает: удаляет элемент из начала списка
 * Выходные данные: значение удаленного элемента
 */
int PopFront(List& head, List& tail) {
    if (head == nullptr) return -1;

    List front = head;
    int value = front->value;
    head = front->next;

    if (head != nullptr) head->prev = nullptr;
    else tail = nullptr;

    delete front;
    return value;
}

/**
 * Входные данные: указатель на начало/конец списка
 * Что делает: удаляет элемент из конца списка
 * Выходные данные: значение удаленного элемента
 */
int PopBack(List& head, List& tail) {
    if (tail == nullptr) return -1;

    List back = tail;
    int value = back->value;
    tail = back->prev;

    if (tail != nullptr) tail->next = nullptr;
    else head = nullptr;

    delete back;
    return value;
}

/**
 * Входные данные: указатель на элемент
 * Что делает: добавляет новый элемент после указанного элемента
 * Выходные данные: ничего
 */
void Insert(List& item, int value) {
    List temp = new Item;

    temp->value = value;
    temp->next = item->next;
    temp->prev = item;

    if (item->next != nullptr) item->next->prev = temp;
    item->next = temp;
}

void InsertBefore(List& item, int value) {
    List temp = new Item;

    temp->value = value;
    temp->next = item;
    temp->prev = item->prev;

    if (item->prev != nullptr) item->prev->next = temp;
    item->prev = temp;
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

    List head = nullptr;
    List tail = nullptr;

    int size = 0;
    for (int i = 0; i < n; i++) {
        char operation;
        cin >> operation;

        int index;

        switch (operation) {
            case '+': {
                cin >> index;
                PushBack(head, tail, index);
                size++;

                break;
            }
            case '*': {
                cin >> index;

                if (head == nullptr) {
                    PushFront(head, tail, index);
                } else {
                    List center_item = head;
                    int center_index = (size / 2) + (size % 2 == 0 ? 1 : 0);

                    for (int j = 0; j < center_index - 1; j++) {
                        center_item = center_item->next;
                    }

                    if (size % 2 == 0) {
                        Insert(center_item, index);
                    } else {
                        InsertBefore(center_item, index);
                    }
                }
                size++;

                break;
            }
            case '-': {
                cout << PopFront(head, tail) << endl;
                size--;

                break;
            }
            default:
                break;
        }
    }

    return 0;
}
