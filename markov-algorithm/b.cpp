/**
 * ЮФУ, ИКТИБ, МОП ЭВМ
 * Программирование и основы теории алгоритмов
 * Домашнее задание №3
 * Нормальный алгоритм Маркова
 * Кожемякин Ярослав Дмитриевич (КТбо1-7)
 * 26.04.2024
 */

#include <clocale>
#include <iostream>
#include <map>

using namespace std;

string ToBinary(string number, map<char, string> replacements, int index) {
    char symbol = number[index];

    string replacement = replacements[symbol];

    cout << '(' << symbol - '0' + 1 << ')' << ' ';

    for (int i = 0; i < number.size(); i++) {
        if (i == index) {
            cout << "\033[1;31m" << symbol << "\033[0m";
        } else {
            cout << number[i];
        }
    }

    cout << " -> ";

    number = number.substr(0, index) + replacement + number.substr(index + 1);

    cout << number << endl;

    return number;
}

string ToHex(string number, map<string, string> replacements, int index) {
    string symbols = "";

    for (int i = index; i < index + 4; i++) {
        symbols += number[i];
    }

    string replacement = replacements[symbols];

    cout << '(' << replacement << ')' << ' ';

    for (int i = 0; i < number.size(); i++) {
        if (i >= index && i < index + 4) {
            cout << "\033[1;31m" << symbols << "\033[0m";
            i += 3;
        } else {
            cout << number[i];
        }
    }

    cout << " -> ";

    // number = number.substr(0, index) + replacement + number.substr(index + 4);

    cout << number << endl;

    return number;
}

int main() {
    setlocale(LC_ALL, "Russian");

    // cout << "\033[1;31mВведите входное слово: \033[0m";
    cout << "Введите входное слово: ";

    string number;
    cin >> number;

    map<char, string> binary_replacements = {
        {'0', "00"},
        {'1', "01"},
        {'2', "10"},
        {'3', "11"}};

    map<string, string> hex_replacements = {
        {"0000", "0"},
        {"0001", "1"},
        {"0010", "2"},
        {"0011", "3"},
        {"0100", "4"},
        {"0101", "5"},
        {"0110", "6"},
        {"0111", "7"},
        {"1000", "8"},
        {"1001", "9"},
        {"1010", "A"},
        {"1011", "B"},
        {"1100", "C"},
        {"1101", "D"},
        {"1110", "E"},
        {"1111", "F"}};

    int string_size = number.size();

    for (int i = 0; i / 2 < string_size; i += 2) {
        number = ToBinary(number, binary_replacements, i);
    }

    int zeroes = 4 - (number.size() % 4);

    if (zeroes != 4) {
        string previous = number;

        for (int i = 0; i < zeroes; i++) {
            number = '0' + number;
        }

        cout << "Добавляем недостающие нули: " << previous << " -> ";
        for (int i = 0; i < number.size(); i++) {
            if (i < number.size() - previous.size()) {
                cout << "\033[1;31m" << '0' << "\033[0m";
            } else {
                cout << number[i];
            }
        }
        cout << endl;
    }

    string_size = number.size();

    for (int i = 0; i / 2 < string_size; i += 2) {
        number = ToHex(number, hex_replacements, i);
    }

    cout << "Результат: " << number << endl;

    return 0;
}
