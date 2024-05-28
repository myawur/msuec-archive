#include <iostream>

using namespace std;

/**
 * Структура элемента стека
 */
typedef struct Node {
    char value;
    Node* next;
}* Stack;

/**
 * Входные данные: указатели на конец начало стека, значение элемента
 * Что делает: добавляет элемент в голову стека
 * Выходные данные: ничего
 */
void Push(Stack& head, char value) {
    Stack new_item = new Node;
    new_item->value = value;
    new_item->next = head;
    head = new_item;
}

/**
 * Входные данные: указатель на начало стека
 * Что делает: удаляет элемент из головы стека
 * Выходные данные: значение удаленного элемента
 */
int Pop(Stack& head) {
    if (head == nullptr) return -1;

    Stack top = head;
    char value = top->value;
    head = top->next;

    delete top;
    return value;
}

/**
 * Входные данные: указатель на голову стеку
 * Что делает: возвращает элемент из головы стека
 * Выходные данные: значение удаленного элемента
 */
int Top(Stack& head) {
    if (head == nullptr) return -1;

    return head->value;
}

/**
 * Входные данные: указатель на голову стека
 * Что делает: удаляет все элементы из стека
 * Выходные данные: ничего
 */
void Clear(Stack& head) {
    while (head != nullptr) {
        Stack next = head->next;
        delete head;
        head = next;
    }
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
    int n;
    cin >> n;

    string s;
    cin >> s;

    Stack head = nullptr;

    for (int i = 0; i < n; i++) {
        char symbol = s[i];

        if (symbol == '(' || symbol == '[' || symbol == '{') {
            Push(head, symbol);
        } else if (symbol == ')' || symbol == ']' || symbol == '}') {
            if (Empty(head)) {
                cout << "NO" << endl;
                return 0;
            }

            char top = Top(head);
            if ((top == '(' && symbol == ')') || (top == '[' && symbol == ']') || (top == '{' && symbol == '}')) {
                Pop(head);
            } else {
                cout << "NO" << endl;
                return 0;
            }
        }
    }

    if (Empty(head)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
