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

string ToHex(string number, map<string, string> replacements) {
    string hex = "";
    for (int i = 0; i < number.size(); i += 4) {
        string quad = number.substr(i, 4);
        hex += replacements[quad];
    }
    return hex;
}

int main() {
    setlocale(LC_ALL, "Russian");

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

    string binary = number;
    for (int i = 0; i < number.size(); i++) {
        binary = ToBinary(binary, binary_replacements, i + i);
    }

    int zeroes = 4 - (binary.size() % 4);

    if (zeroes != 4) {
        string previous = binary;

        for (int i = 0; i < zeroes; i++) {
            binary = '0' + binary;
        }

        cout << "Добавляем недостающие нули: " << binary << " -> ";
        for (int i = 0; i < binary.size(); i++) {
            if (i < binary.size() - previous.size()) {
                cout << "\033[1;31m" << '0' << "\033[0m";
            } else {
                cout << binary[i];
            }
        }
        cout << endl;
    }

    string hex = ToHex(binary, hex_replacements);

    cout << "Результат: " << hex << endl;

    return 0;
}