/**
 * ЮФУ, ИКТИБ, МОП ЭВМ
 * Структуры и алгоритмы обработки данных
 * Домашнее задание №6.1
 * Задание A
 * Кожемякин Ярослав Дмитриевич (КТбо1-7)
 * 06.05.2024
 */

#include <iostream>
#include <vector>

using namespace std;

/**
 * Входные данные: подстрока + разделитель + строка
 * Что делает: вычисляет префиксную функциюrw для входной строки через алгоритм Кнута-Морриса-Пратта
 * Выходные данные: префиксная функция
 */
vector<int> prefix_function(string s) {
    int n = s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j]) {
            j = pi[j - 1];
        }
        if (s[i] == s[j]) {
            j++;
        }
        pi[i] = j;
    }
    return pi;
}

/**
 * Входные данные: void
 * Что делает: решает задачу
 * Выходные данные: void
 */
void solve() {
    string a, b;
    cin >> a >> b;

    string s = a + '#' + b;

    vector<int> pi = prefix_function(s);

    for (auto &i : pi) {
        if (i == a.size()) {
            cout << "yes" << endl;
            return;
        }
    }

    cout << "no" << endl;
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