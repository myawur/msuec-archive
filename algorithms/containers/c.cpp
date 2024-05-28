/**
 * ЮФУ, ИКТИБ, МОП ЭВМ
 * Структуры и алгоритмы обработки данных
 * Домашнее задание №3.1
 * Задание C
 * Исполнитель: Кожемякин Ярослав Дмитриевич (КТбо1-7)
 * 12.03.2024
 */

#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    map<string, int> clients;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int type;
        cin >> type;

        string name;
        cin >> name;

        if (type == 1) {
            int amount;
            cin >> amount;

            clients[name] += amount;
        } else if (type == 2) {
            if (clients.find(name) == clients.end()) {
                cout << "ERROR" << endl;
            } else {
                cout << clients[name] << endl;
            }
        }
    }

    return 0;
}
