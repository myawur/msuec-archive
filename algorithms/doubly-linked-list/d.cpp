/**
 * ЮФУ, ИКТИБ, МОП ЭВМ
 * Практикум по программированию
 * Практическое занятие №1.1
 * Задание A
 * Исполнитель: Кожемякин Ярослав Дмитриевич (КТбо1-7)
 * 20.02.2024
 */

#include <iostream>

using namespace std;

/**
 * Структура элемента стека
 */
typedef struct Item {
    int value;
    Item* next;
}* Stack;

/**
 * Входные данные: указатели на конец начало стека, значение элемента
 * Что делает: добавляет элемент в голову стека
 * Выходные данные: ничего
 */
void Push(Stack& head, int value, int& stack_size) {
    Stack new_item = new Item;
    new_item->value = value;
    new_item->next = head;
    head = new_item;
    stack_size++;
}

/**
 * Входные данные: указатель на начало стека
 * Что делает: удаляет элемент из головы стека
 * Выходные данные: значение удаленного элемента
 */
int Pop(Stack& head, int& stack_size) {
    if (head == nullptr) return -1;

    Stack top = head;
    int value = top->value;
    head = top->next;

    if (stack_size > 0) stack_size--;

    delete top;
    return value;
}

/**
 * Входные данные: указатель на голову стеку
 * Что делает: возвращает элемент из головы стека
 * Выходные данные: значение удаленного элемента
 */
int Back(Stack& head) {
    if (head == nullptr) return -1;

    return head->value;
}

/**
 * Входные данные: указатель на голову стека
 * Что делает: удаляет все элементы из стека
 * Выходные данные: ничего
 */
void Clear(Stack& head, int& stack_size) {
    while (head != nullptr) {
        Stack next = head->next;
        delete head;
        head = next;
    }
    stack_size = 0;
}

/**
 * Входные данные: указатель на голову стека
 * Что делает: проверяет, пуст ли стек
 * Выходные данные: true, если список пуст, иначе false
 */
bool Empty(Stack head) {
    return head == nullptr;
}

int main() {
    string s;
    int n;

    int stack_size = 0;

    Stack head = nullptr;

    bool stop = false;
    while (!stop) {
        cin >> s;

        if (s == "push") {
            cin >> n;
            Push(head, n, stack_size);
            cout << "ok" << endl;
        } else if (s == "pop") {
            if (Empty(head)) {
                cout << "error" << endl;
            } else {
                int value = Pop(head, stack_size);
                cout << value << endl;
            }
        } else if (s == "back") {
            if (Empty(head)) {
                cout << "error" << endl;
            } else {
                int value = Back(head);
                cout << value << endl;
            }
        } else if (s == "size") {
            cout << stack_size << endl;
        } else if (s == "clear") {
            Clear(head, stack_size);
            cout << "ok" << endl;
        } else {
            cout << "bye" << endl;
            stop = true;
        }
    }

    return 0;
}
