/**
 * ЮФУ, ИКТИБ, МОП ЭВМ
 * Структуры и алгоритмы обработки данных
 * Домашнее задание №3.2
 * Задание D
 * Исполнитель: Кожемякин Ярослав Дмитриевич (КТбо1-7)
 * 19.03.2024
 */

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
 * Входные данные: указатель на ноду
 * Что делает: рекурсивно проходит по всему дереву и выводит вершины, у которых один ребенок
 * Выходные данные: ничего
 */
void FindNodes(Node* node) {
    if (node != nullptr) {
        FindNodes(node->left);

        if ((node->left != nullptr && node->right == nullptr) || (node->left == nullptr && node->right != nullptr)) {
            cout << node->value << endl;
        }

        FindNodes(node->right);
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

    FindNodes(root);

    return 0;
}
