/**
 * ЮФУ, ИКТИБ, МОП ЭВМ
 * Структуры и алгоритмы обработки данных
 * Домашнее задание №4.3
 * Задание I
 * Исполнитель: Кожемякин Ярослав Дмитриевич (КТбо1-7)
 * 08.04.2024
 */

#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main() {
    int n, k;
    cin >> n >> k;

    vector<vector<ll>> dp(k + 1, vector<ll>(k + 1));
    dp[0][0] = 1;

    for (int j = 1; j <= k; j++) {
        for (int i = 0; i <= j; i++) {
            if (i > 0) {
                dp[i][j] += dp[i - 1][j - 1];
            }
            if (i < j) {
                dp[i][j] += dp[i + 1][j - 1];
            }
            if (i == 0 && j != k) {
                dp[i][j] = 0;
            }
        }
    }

    cout << dp[n][k] << endl;

    return 0;
}
