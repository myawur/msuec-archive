/**
 * ЮФУ, ИКТИБ, МОП ЭВМ
 * Структуры и алгоритмы обработки данных
 * Домашнее задание №4.3
 * Задание G
 * Исполнитель: Кожемякин Ярослав Дмитриевич (КТбо1-7)
 * 08.04.2024
 */

#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> dp(n + 1, n + 1);
    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j * j * j <= i; j++) {
            dp[i] = min(dp[i], dp[i - j * j * j] + 1);
        }
    }

    cout << dp[n] << endl;

    return 0;
}
