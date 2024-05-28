/**
 * ЮФУ, ИКТИБ, МОП ЭВМ
 * Структуры и алгоритмы обработки данных
 * Домашнее задание №3.1
 * Задание A
 * Исполнитель: Кожемякин Ярослав Дмитриевич (КТбо1-7)
 * 12.03.2024
 */

#include <iostream>
#include <set>

using namespace std;

int main() {
    string a, b;
    cin >> a >> b;

    string c = a + b;
    set<char> d(c.begin(), c.end());

    string result = "";
    for (char i = 'a'; i <= 'z'; i++) {
        if (d.find(i) == d.end() && d.find(toupper(i)) == d.end()) {
            result += toupper(i);
        }
    }

    if (result != "") {
        cout << result << endl;
    } else {
        cout << '0' << endl;
    }

    return 0;
}
