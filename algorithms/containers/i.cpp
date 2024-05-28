/**
 * ЮФУ, ИКТИБ, МОП ЭВМ
 * Структуры и алгоритмы обработки данных
 * Лабораторная работа №3
 * Задание C
 * Исполнитель: Кожемякин Ярослав Дмитриевич (КТбо1-7)
 * 30.03.2024
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
 * Входные данные: указатель на ноду, ссылка на высоту
 * Что делает: рекурсивно проходит по всему дереву и находит диаметр
 * Выходные данные: диаметр дерева
 */
int FindDiameter(Node* node, int& height) {
    if (node == nullptr) {
        return 0;
    }

    int left_height = 0, right_height = 0;

    int left_diameter = FindDiameter(node->left, left_height);
    int right_diameter = FindDiameter(node->right, right_height);

    height = max(left_height, right_height) + 1;

    return max(left_height + right_height + 1, max(left_diameter, right_diameter));
}

int main() {
    int value;
    cin >> value;

    Node* root = nullptr;

    while (value != 0) {
        root = Insert(root, value);
        cin >> value;
    }

    int height = 0;

    cout << FindDiameter(root, height) << endl;

    return 0;
}
