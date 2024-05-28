/**
 * ЮФУ, ИКТИБ, МОП ЭВМ
 * Структуры и алгоритмы обработки данных
 * Домашнее задание №4.3
 * Задание H
 * Исполнитель: Кожемякин Ярослав Дмитриевич (КТбо1-7)
 * 08.04.2024
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<vector<int>> dp(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        dp[i][i] = arr[i];
    }

    for (int len = 2; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            dp[i][j] = max(arr[i] + min(i + 2 <= j ? dp[i + 2][j] : 0, i + 1 <= j - 1 ? dp[i + 1][j - 1] : 0),
                           arr[j] + min(i + 1 <= j - 1 ? dp[i + 1][j - 1] : 0, i <= j - 2 ? dp[i][j - 2] : 0));
        }
    }

    int total = 0;
    for (int i = 0; i < n; i++) {
        total += arr[i];
    }

    if (dp[0][n - 1] > total - dp[0][n - 1]) {
        cout << 1 << endl;
    } else if (dp[0][n - 1] < total - dp[0][n - 1]) {
        cout << 2 << endl;
    } else {
        cout << 0 << endl;
    }

    return 0;
}
