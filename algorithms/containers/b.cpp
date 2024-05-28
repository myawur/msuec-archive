/**
 * ЮФУ, ИКТИБ, МОП ЭВМ
 * Структуры и алгоритмы обработки данных
 * Домашнее задание №3.1
 * Задание B
 * Исполнитель: Кожемякин Ярослав Дмитриевич (КТбо1-7)
 * 12.03.2024
 */

#include <climits>
#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    map<string, pair<int, int>> devices;

    for (int i = 0; i < 6; i++) {
        string friend_name, device_name;
        int price;

        cin >> friend_name >> device_name >> price;

        if (devices.find(device_name) == devices.end()) {
            devices[device_name] = {1, price};
        } else {
            devices[device_name].first++;
            if (price < devices[device_name].second) {
                devices[device_name].second = price;
            }
        }
    }

    string best_device;
    int max_count = 0, min_price = INT_MAX;

    for (const auto& device : devices) {
        if (device.second.first > max_count || (device.second.first == max_count && device.second.second < min_price)) {
            max_count = device.second.first;
            min_price = device.second.second;
            best_device = device.first;
        }
    }

    cout << best_device << endl;

    return 0;
}
