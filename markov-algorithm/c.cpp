#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

char ToQuad(string input, int i, map<string, char>& hex_map) {
    string sub = input.substr(i, 2);

    if (hex_map.find(sub) != hex_map.end()) {
        for (int j = 0; j < input.size(); j++) {
            
        }
        cout << '(' << hex_map[sub] << ')' << ' ';
        cout << "\033[1;31m" << sub << "\033[0m";
        cout << input.substr(2, input.size());
        cout << " -> ";
        cout << hex_map[sub] << input.substr(2, input.size()) << endl;

        return hex_map[sub];
    }
    return '\0';
}

int main() {
    map<string, char> hex_map = {
        {"00", '0'},
        {"01", '1'},
        {"02", '2'},
        {"03", '3'},
        {"10", '4'},
        {"11", '5'},
        {"12", '6'},
        {"13", '7'},
        {"20", '8'},
        {"21", '9'},
        {"22", 'A'},
        {"23", 'B'},
        {"30", 'C'},
        {"31", 'D'},
        {"32", 'E'},
        {"33", 'F'}};

    string input;

    cout << "Введите входное слово: ";
    cin >> input;

    if (input.size() % 2 != 0) {
        cout << "Добавляем ноль, чтобы количество цифр было четным: ";

        string previous = input;

        cout << input << " -> ";

        input = '0' + input;

        cout << "\033[1;31m" << '0' << "\033[0m";
        cout << previous << endl;
    }

    string output;
    for (size_t i = 0; i < input.size(); i += 2) {
        char quad = ToQuad(input, i, hex_map);
        if (quad != '\0') {
            output += quad;
        }
    }

    cout << "Результат: " << output << endl;

    return 0;
}