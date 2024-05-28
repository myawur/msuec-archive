/**
 * ЮФУ, ИКТИБ, МОП ЭВМ
 * Структуры и алгоритмы обработки данных
 * Домашнее задание №7
 * Задание A
 * Кожемякин Ярослав Дмитриевич (КТбо1-7)
 * 23.05.2024
 */

#include <bits/stdc++.h>

using namespace std;

/**
 * Структура точки
 * x, y - координаты
 */
struct Point {
    double x, y;
};

/**
 * Входные данные: три трочки
 * Что делает: считает векторное произведение
 * Выходные данные: векторное произведение
 */
double vector_product(Point a, Point b, Point c) {
    double dx1 = b.x - a.x;
    double dy1 = b.y - a.y;
    double dx2 = c.x - b.x;
    double dy2 = c.y - b.y;
    return dx1 * dy2 - dy1 * dx2;
}

/**
 * Входные данные: void
 * Что делает: решает задачу
 * Выходные данные: void
 */
void solve() {
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}