/**
 * ЮФУ, ИКТИБ, МОП ЭВМ
 * Структуры и алгоритмы обработки данных
 * Домашнее задание №7
 * Задание B
 * Кожемякин Ярослав Дмитриевич (КТбо1-7)
 * 23.05.2024
 */

#include <bits/stdc++.h>

using namespace std;

/**
 * Входные данные: координаты двух точек
 * Что делает: вычисляет квадрат расстояния между двумя точками
 * Выходные данные: квадрат расстояния между двумя точками
 */
double squared_distance(double x1, double y1, double x2, double y2) {
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

/**
 * Входные данные: координаты двух точек
 * Что делает: вычисляет расстояние между двумя точками
 * Выходные данные: расстояние между двумя точками
 */
double distance(double x1, double y1, double x2, double y2) {
    return sqrt(squared_distance(x1, y1, x2, y2));
}

/**
 * Входные данные: координаты трех точек A, B, C
 * Что делает: вычисляет расстояние от точки C до отрезка AB
 * Выходные данные: расстояние от точки C до отрезка AB
 */
double point_to_segment_distance(double ax, double ay, double bx, double by, double cx, double cy) {
    double ab_x = bx - ax;
    double ab_y = by - ay;
    double ac_x = cx - ax;
    double ac_y = cy - ay;

    double ab_ab = ab_x * ab_x + ab_y * ab_y;
    double ab_ac = ab_x * ac_x + ab_y * ac_y;

    double d = ab_ac / ab_ab;
    d = max(0.0, min(1.0, d));

    double dx = ax + d * ab_x;
    double dy = ay + d * ab_y;
    return distance(cx, cy, dx, dy);
}

/**
 * Входные данные: void
 * Что делает: решает задачу
 * Выходные данные: void
 */
void solve() {
    double ax, ay, bx, by, cx, cy, l;
    cin >> ax >> ay >> bx >> by >> cx >> cy >> l;

    double min_dist = point_to_segment_distance(ax, ay, bx, by, cx, cy);

    double dist_a = distance(cx, cy, ax, ay);
    double dist_b = distance(cx, cy, bx, by);
    double max_dist = max(dist_a, dist_b);

    double answer1 = max(0.0, min_dist - l);
    double answer2 = max(0.0, max_dist - l);

    cout << fixed << setprecision(2);
    cout << answer1 << endl;
    cout << answer2 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}