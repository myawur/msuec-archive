/**
 * ЮФУ, ИКТИБ, МОП ЭВМ
 * Структуры и алгоритмы обработки данных
 * Лабораторная работа №1
 * Задание C
 * Исполнитель: Кожемякин Ярослав Дмитриевич (КТбо1-7)
 * 02.03.2024
 */

#include <cstdio>
#include <list>

using namespace std;

typedef long long ll;

int main() {
    int n;
    ll k;
    // cin >> n >> k;
    scanf("%d%I64d", &n, &k);

    list<int> knights;

    int winner;
    for (int i = 0; i < n; i++) {
        int knight;
        // cin >> knight;
        scanf("%d", &knight);

        if (!i) winner = knight;
        else knights.push_back(knight);
    }

    int streak = 0;
    bool first_lose = true;

    ll min_streak = min(ll(n), k);

    while (streak < min_streak) {
        int knight = knights.front();

        if (winner > knight) {
            streak++;
            knights.push_back(knights.front());
            knights.pop_front();
        } else {
            streak = 1;

            if (!first_lose) {
                winner = knight;
                knights.push_back(knights.front());
                knights.pop_front();
            } else {
                knights.push_back(winner);
                first_lose = false;
            }
        }
    }

    // cout << winner << endl;
    printf("%d\n", winner);

    return 0;
}
