/**
 * ЮФУ, ИКТИБ, МОП ЭВМ
 * Структуры и алгоритмы обработки данных
 * Домашнее задание №6.2
 * Задание D
 * Кожемякин Ярослав Дмитриевич (КТбо1-7)
 * 13.05.2024
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/**
 * Входные данные: void
 * Что делает: решает задачу
 * Выходные данные: void
 */
void solve() {
    int n;
    cin >> n;

    if (n == 0) {
        cout << 0 << endl;
        return;
    }

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    int sum = 0;
    vector<int> prefix_sum(n + 1);
    for (int i = 0; i < n; i++) {
        if (i > 1 && a[i] > prefix_sum[i - 1]) {
            break;
        }
        prefix_sum[i + 1] = prefix_sum[i] + a[i];
        sum = prefix_sum[i + 1];
    }

    cout << sum << endl;
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