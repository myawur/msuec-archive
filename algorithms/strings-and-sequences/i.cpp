/**
 * ЮФУ, ИКТИБ, МОП ЭВМ
 * Структуры и алгоритмы обработки данных
 * Лабораторная работа №7
 * Задание C
 * Кожемякин Ярослав Дмитриевич (КТбо1-7)
 * 25.05.2024
 */

#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

/**
 * Входные данные: void
 * Что делает: решает задачу
 * Выходные данные: void
 */
void solve() {
    int n;
    cin >> n;

    vector<ll> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    ll max_pos = LLONG_MIN, max_neg = LLONG_MIN;
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] > 0) {
            max_pos = max(max_pos, v[i]);
            if (i > 0 && v[i - 1] < 0) {
                sum += max_neg;
                max_neg = LLONG_MIN;
            }
        } else {
            max_neg = max(max_neg, v[i]);
            if (i > 0 && v[i - 1] > 0) {
                sum += max_pos;
                max_pos = LLONG_MIN;
            }
        }
    }
    sum += max(max_pos, max_neg);

    cout << sum << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}