/**
 * ЮФУ, ИКТИБ, МОП ЭВМ
 * Структуры и алгоритмы обработки данных
 * Домашнее задание №2.2
 * Задание E
 * Исполнитель: Кожемякин Ярослав Дмитриевич (КТбо1-7)
 * 27.02.2024
 */

#include <iostream>
#include <vector>

using namespace std;

/**
 * Входные данные: вектор с координатами стойл, кол-во стойл, кол-во коров, минимальное расстояние
 * Что делает: проверяет, можно ли разместить k коров в стойлах так, чтобы минимальное расстояние между ними было не меньше min_dist
 * Выходные данные: true, если можно разместить, иначе false
 */
bool CanPlace(vector<int>& stalls, int n, int k, int min_dist) {
    int placed = 1;
    int last_placed = stalls[0];

    for (int i = 1; i < n; i++) {
        if (stalls[i] - last_placed >= min_dist) {
            placed++;
            if (placed == k) {
                return true;
            }
            last_placed = stalls[i];
        }
    }

    return false;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> stalls(n);
    for (int i = 0; i < n; i++) {
        cin >> stalls[i];
    }

    int left = 0, right = stalls[n - 1] - stalls[0];
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (CanPlace(stalls, n, k, mid)) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    cout << right << endl;

    return 0;
}