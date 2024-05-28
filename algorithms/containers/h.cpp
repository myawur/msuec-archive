/**
 * ЮФУ, ИКТИБ, МОП ЭВМ
 * Структуры и алгоритмы обработки данных
 * Лабораторная работа №3
 * Задание B
 * Исполнитель: Кожемякин Ярослав Дмитриевич (КТбо1-7)
 * 30.03.2024
 */

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    unordered_map<int, int> ants;
    vector<int> coords;

    int sum = 0;

    for (int i = 0; i < n; i++) {
        int amount, coord;
        cin >> amount >> coord;

        ants[coord] += amount;
        sum += amount;

        coords.push_back(coord);
    }

    int m;
    cin >> m;

    int eaten = 0;

    for (int i = 0; i < m; i++) {
        int jump;
        cin >> jump;

        auto element = lower_bound(coords.begin(), coords.end(), jump);

        if (element != coords.end()) {
            eaten += ants[*element];

            ants.erase(*element);
            coords.erase(element);
        }
    }

    cout << abs(sum - eaten) << endl;

    return 0;
}
