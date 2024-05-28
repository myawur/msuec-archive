/**
 * ЮФУ, ИКТИБ, МОП ЭВМ
 * Структуры и алгоритмы обработки данных
 * Домашнее задание №6.1
 * Задание B
 * Кожемякин Ярослав Дмитриевич (КТбо1-7)
 * 06.05.2024
 */

#include <algorithm>
#include <cctype>
#include <iostream>
#include <vector>

using namespace std;

/**
 * Входные данные: void
 * Что делает: решает задачу
 * Выходные данные: void
 */
void solve() {
    string s;
    getline(cin, s);

    for (int i = 0; i < s.size(); i++) {
        s[i] = toupper(s[i]);
        if (s[i] < 65 || s[i] > 90) {
            s.erase(i, 1);
            i--;
        }
    }

    vector<int> v(26, 0);
    for (int i = 0; i < s.size(); i++) {
        v[s[i] - 'A']++;
    }

    int count = 0;
    for (int i = 0; i < 26; i++) {
        if (v[i] % 2 != 0) {
            count++;
        }
    }

    if (count > 1) {
        cout << "NO" << endl;
        return;
    }

    string half = "", middle = "";
    for (int i = 25; i >= 0; i--) {
        for (int j = 0; j < v[i] / 2; j++) {
            half += (char)('A' + i);
        }
        if (v[i] % 2 != 0) {
            middle = (char)(i + 'A');
        }
    }

    string result = half + middle;
    reverse(half.begin(), half.end());
    result += half;
    cout << result << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}