/**
 * ЮФУ, ИКТИБ, МОП ЭВМ
 * Структуры и алгоритмы обработки данных
 * Домашнее задание №4.2
 * Задание E
 * Исполнитель: Кожемякин Ярослав Дмитриевич (КТбо1-7)
 * 01.04.2024
 */

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> rooms(n + 2, vector<int>(m + 2));
    vector<vector<int>> dp(n + 2, vector<int>(m + 2, 0));

    dp[1][1] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> rooms[i + 1][j + 1];

            if (rooms[i + 1][j + 1]) {
                dp[i + 1][j + 1] += (dp[i][j + 1] + dp[i + 1][j]);
            }
        }
    }

    if (dp[n][m]) {
        cout << dp[n][m] << endl;
    } else {
        cout << "Impossible" << endl;
    }

    return 0;
}
