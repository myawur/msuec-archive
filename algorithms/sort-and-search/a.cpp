/**
 * ЮФУ, ИКТИБ, МОП ЭВМ
 * Структуры и алгоритмы обработки данных
 * Домашнее задание №2.1
 * Задание A
 * Исполнитель: Кожемякин Ярослав Дмитриевич (КТбо1-7)
 * 27.02.2024
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> cards(n);

    for (auto &card : cards) {
        cin >> card;
    }

    sort(cards.begin(), cards.end(), greater<int>());

    int player_sum = 0;
    for (int i = 0; i < n / 2; i++) {
        player_sum += cards[i];
    }

    int dealer_sum = 0;
    for (int i = n / 2; i < n; i++) {
        dealer_sum += cards[i];
    }

    cout << player_sum - dealer_sum << endl;

    return 0;
}