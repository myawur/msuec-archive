/**
 * ЮФУ, ИКТИБ, МОП ЭВМ
 * Практикум по программированию
 * Домашнее задание №6.2
 * Задание D
 * Кожемякин Ярослав Дмитриевич (КТбо1-7)
 * 18.05.2024
 */

#include <algorithm>
#include <iostream>
#include <numeric>
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

    vector<int> arr(n);
    for (int k = 0; k < n; k++) {
        cin >> arr[k];
    }

    if (n == 0) {
        cout << 0 << endl;
    } else if (n <= 2) {
        cout << accumulate(arr.begin(), arr.end(), 0) << endl;
    } else {
        sort(arr.begin(), arr.end());

        int l = 0, r = 1;
        int sum = arr[l] + arr[r], result_sum = 0;
        while (r < n - 1) {
            while (r < n - 1 && arr[l] + arr[l + 1] >= arr[r + 1]) {
                r++;
                sum += arr[r];
                result_sum = max(result_sum, sum);
            }
            if (l < r) {
                sum -= arr[l];
                l++;
            }
        }

        cout << result_sum << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}