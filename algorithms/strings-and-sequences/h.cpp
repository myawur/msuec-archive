/**
 * ЮФУ, ИКТИБ, МОП ЭВМ
 * Структуры и алгоритмы обработки данных
 * Лабораторная работа №7
 * Задание B
 * Кожемякин Ярослав Дмитриевич (КТбо1-7)
 * 25.05.2024
 */

#include <iostream>
#include <vector>

using namespace std;

/**
 * Входные данные: void
 * Что делает: решает задачу
 * Выходные данные: void
 */
void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> h(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }

    int sum = 0;
    for (int i = 0; i < k; i++) {
        sum += h[i];
    }

    int min_sum = sum, min_index = 0;
    for (int i = k; i < n; i++) {
        sum = sum - h[i - k] + h[i];
        if (sum < min_sum) {
            min_sum = sum;
            min_index = i - k + 1;
        }
    }

    cout << min_index + 1 << endl;
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