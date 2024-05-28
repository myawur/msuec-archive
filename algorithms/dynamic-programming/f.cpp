/**
 * ЮФУ, ИКТИБ, МОП ЭВМ
 * Структуры и алгоритмы обработки данных
 * Домашнее задание №4.2
 * Задание F
 * Исполнитель: Кожемякин Ярослав Дмитриевич (КТбо1-7)
 * 01.04.2024
 */

#include <iostream>
#include <vector>

const int kBoardHeight = 8;
const int kBoardWidth = 8;

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> dp(kBoardHeight + 2, vector<int>(kBoardWidth + 2, 0));

    dp[m][n] = 1;

    for (int i = m + 1; i <= kBoardHeight; i++) {
        for (int j = 1; j <= kBoardWidth; j++) {
            dp[i][j] += dp[i - 1][j + 1];
            dp[i][j] += dp[i - 1][j - 1];
        }
    }

    int sum = 0;

    for (int i = 1; i <= kBoardWidth; i++) {
        sum += dp[kBoardHeight][i];
    }

    cout << sum << endl;

    return 0;
}
