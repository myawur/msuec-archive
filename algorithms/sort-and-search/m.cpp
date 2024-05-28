/**
 * ЮФУ, ИКТИБ, МОП ЭВМ
 * Структуры и алгоритмы обработки данных
 * Лабораторная работа №2
 * Задание C
 * Исполнитель: Кожемякин Ярослав Дмитриевич (КТбо1-7)
 * 16.03.2024
 */

#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> a(n);

    for (auto &e : a) {
        cin >> e;
    }

    sort(a.begin(), a.end());

    int l = 0, r = n - 1;
    int min_diff = INT_MAX, max_range = INT_MIN;
    int p, q;

    while (l < r) {
        int diff = abs(a[l] + a[r] - x);
        int range = r - l;

        if (diff < min_diff || (diff == min_diff && range > max_range)) {
            min_diff = diff;
            max_range = range;
            p = a[l];
            q = a[r];
        }

        if (a[l] + a[r] < x) {
            l++;
        } else {
            r--;
        }
    }

    cout << p << ' ' << q << ' ' << min_diff << endl;

    return 0;
}
