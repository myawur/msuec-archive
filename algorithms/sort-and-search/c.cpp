/**
 * ЮФУ, ИКТИБ, МОП ЭВМ
 * Структуры и алгоритмы обработки данных
 * Домашнее задание №2.1
 * Задание C
 * Исполнитель: Кожемякин Ярослав Дмитриевич (КТбо1-7)
 * 27.02.2024
 */

#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

int main() {
    string s;
    cin >> s;

    multimap<char, int> indices;
    for (int i = 0; i < s.size(); i++) {
        indices.insert({s[i], i + 1});
    }

    sort(s.begin(), s.end());

    bool is_correct = true;
    for (int i = 0; i < s.size() && is_correct; i++) {
        if (i > s[i] - 65) is_correct = false;
    }

    if (is_correct) {
        cout << "YES" << endl;
        for (const auto &c : s) {
            auto a = indices.find(c);
            cout << a->second << ' ';
            indices.erase(a);
        }
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
