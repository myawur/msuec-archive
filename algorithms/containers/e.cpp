/**
 * ЮФУ, ИКТИБ, МОП ЭВМ
 * Структуры и алгоритмы обработки данных
 * Домашнее задание №3.2
 * Задание E
 * Исполнитель: Кожемякин Ярослав Дмитриевич (КТбо1-7)
 * 19.03.2024
 */

#include <climits>
#include <iostream>

using namespace std;

/**
 * Структура бинарного дерева
 */
struct Node {
    int value;
    Node* left;
    Node* right;
};

/**
 * Входные данные: значение элемента
 * Что делает: создает новую ноду в дереве
 * Выходные данные: созданная нода
 */
Node* NewNode(int value) {
    Node* node = new Node;
    node->value = value;
    node->left = node->right = nullptr;

    return node;
}

/**
 * Входные данные: указатель на ноду, значение элемента
 * Что делает: добавляет элемент в дерево
 * Выходные данные: созданная вершина
 */
Node* Insert(Node* node, int value) {
    if (node == nullptr) {
        return NewNode(value);
    }

    if (value < node->value) {
        node->left = Insert(node->left, value);
    } else if (value > node->value) {
        node->right = Insert(node->right, value);
    }

    return node;
}

/**
 * Входные данные: указатель на ноду, указатель максимального числа, лимит максимального числа
 * Что делает: рекурсивно проходит по всему дереву и находит максимальное число
 * Выходные данные: void
 */
void FindMax(Node* node, int* max_value, int max_limit) {
    if (node != nullptr) {
        if (node->value > *max_value && node->value < max_limit) {
            *max_value = node->value;
        }

        FindMax(node->left, max_value, max_limit);
        FindMax(node->right, max_value, max_limit);
    }
}

int main() {
    int value;
    cin >> value;

    Node* root = nullptr;

    while (value != 0) {
        root = Insert(root, value);
        cin >> value;
    }

    int max_value = INT_MIN;
    FindMax(root, &max_value, INT_MAX);

    int pre_max_value = INT_MIN;
    FindMax(root, &pre_max_value, max_value);

    cout << pre_max_value << endl;

    return 0;
}
