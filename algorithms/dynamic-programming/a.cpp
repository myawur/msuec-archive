/**
 * ЮФУ, ИКТИБ, МОП ЭВМ
 * Структуры и алгоритмы обработки данных
 * Домашнее задание №4.1
 * Задание A
 * Исполнитель: Кожемякин Ярослав Дмитриевич (КТбо1-7)
 * 26.03.2024
 */

#include <climits>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> y(n);
    vector<int> dp(n, INT_MAX);

    for (auto &e : y) {
        cin >> e;
    }

    dp[0] = 0;

    for (int i = 0; i < n - 1; i++) {
        dp[i + 1] = min(dp[i + 1], dp[i] + abs(y[i] - y[i + 1]));
        if (i < n - 2) {
            dp[i + 2] = min(dp[i + 2], dp[i] + abs(y[i] - y[i + 2]) * 3);
        }
    }

    cout << dp[n - 1] << endl;

    return 0;
}
