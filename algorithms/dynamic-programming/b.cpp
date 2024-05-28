/**
 * ЮФУ, ИКТИБ, МОП ЭВМ
 * Структуры и алгоритмы обработки данных
 * Домашнее задание №4.1
 * Задание B
 * Исполнитель: Кожемякин Ярослав Дмитриевич (КТбо1-7)
 * 26.03.2024
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> dp(n + 1, 1e9);
    dp[0] = 0;

    for (int i = 1; i * i <= n; i++) {
        for (int j = i * i; j <= n; j++) {
            dp[j] = min(dp[j], dp[j - i * i] + 1);
        }
    }

    cout << dp[n] << endl;

    return 0;
}
