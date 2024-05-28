/**
 * ЮФУ, ИКТИБ, МОП ЭВМ
 * Структуры и алгоритмы обработки данных
 * Домашнее задание №4.2
 * Задание D
 * Исполнитель: Кожемякин Ярослав Дмитриевич (КТбо1-7)
 * 01.04.2024
 */

#include <climits>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

const double kStraightWay = 100;
const double kDiagonalWay = sqrt(kStraightWay * kStraightWay * 2);

int main() {
    int n, m;
    cin >> n >> m;

    int k;
    cin >> k;

    vector<vector<bool>> diagonals(m + 2, vector<bool>(n + 2, false));

    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;

        diagonals[y][x] = true;
    }

    vector<vector<double>> dp(m + 3, vector<double>(n + 3, INT_MAX));

    dp[1][1] = 0;

    for (int i = 1; i <= m + 1; i++) {
        for (int j = 1; j <= n + 1; j++) {
            dp[i + 1][j] = min(dp[i][j] + kStraightWay, dp[i + 1][j]);
            dp[i][j + 1] = min(dp[i][j] + kStraightWay, dp[i][j + 1]);

            if (diagonals[i][j]) {
                dp[i + 1][j + 1] = min(dp[i][j] + kDiagonalWay, dp[i + 1][j + 1]);
            }
        }
    }

    cout << round(dp[m + 1][n + 1]);

    return 0;
}
