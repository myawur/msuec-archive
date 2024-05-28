/**
 * ЮФУ, ИКТИБ, МОП ЭВМ
 * Программирование и основы теории алгоритмов
 * Домашнее задание №3
 * Проектирование и реализация нормального алгоритма Маркова
 * Кожемякин Ярослав Дмитриевич (КТбо1-7)
 * 26.04.2024
 */

#include <clocale>
#include <iostream>
#include <vector>

using namespace std;

/**
 * Входные данные: входное слово, правила замены
 * Что делает: один раз делает замену
 * Выходные данные: новое измененное слово
 */
string ReplaceRule(string, vector<pair<string, string>>);

/**
 * Входные данные: входное слово
 * Что делает: проверяет входное слово на правильность ввода
 * Выходные данные: true, если входное слово правильное, иначе false
 */
bool IsValidInput(string);

/**
 * Входные данные: ответ пользователя
 * Что делает: проверяет ответ пользователя на правильность ввода
 * Выходные данные: true, если ответ пользователя правильный, иначе false
 */
bool IsValidAnswer(string);

int main() {
    setlocale(LC_ALL, "Russian");

    vector<pair<string, string>> rules = {
        {"aa", "!("},
        {"ab", "!)"},
        {"ac", "!{"},
        {"ad", "!}"},
        {"ba", "!4"},
        {"bb", "!5"},
        {"bc", "!6"},
        {"bd", "!7"},
        {"ca", "!8"},
        {"cb", "!9"},
        {"cc", "!A"},
        {"cd", "!B"},
        {"da", "!C"},
        {"db", "!D"},
        {"dc", "!E"},
        {"dd", "!F"},
        {"%a%", "@a%"},
        {"%b%", "@b%"},
        {"%c%", "@c%"},
        {"%d%", "@d%"},
        {"@a@", "%a@"},
        {"@b@", "%b@"},
        {"@c@", "%c@"},
        {"@d@", "%d@"},
        {"~(!", "0~"},
        {"~)!", "1~"},
        {"~{!", "2~"},
        {"~}!", "3~"},
        {"~4!", "4~"},
        {"~5!", "5~"},
        {"~6!", "6~"},
        {"~7!", "7~"},
        {"~8!", "8~"},
        {"~9!", "9~"},
        {"~A!", "A~"},
        {"~B!", "B~"},
        {"~C!", "C~"},
        {"~D!", "D~"},
        {"~E!", "E~"},
        {"~F!", "F~"},
        {"~(", "0~"},
        {"~)", "1~"},
        {"~{", "2~"},
        {"~}", "3~"},
        {"~a!", "0~"},
        {"~b!", "1~"},
        {"~c!", "2~"},
        {"~d!", "3~"},
        {"~!", "~"},
        {"~", "."},
        {"0", "%a"},
        {"1", "%b"},
        {"2", "%c"},
        {"3", "%d"},
        {"%", ""},
        {"@", ""},
        {"a", "~a!"},
        {"b", "~b!"},
        {"c", "~c!"},
        {"d", "~d!"},
        {"!", "~"}};

    bool is_active = true;

    while (is_active) {
        string number;

        do {
            cout << "Введите входное слово: ";
            cin >> number;

            if (number == "exit") {
                return 0;
            }

            if (!IsValidInput(number)) {
                cout << "Неправильный ввод, повторите заново или выйдите из программы, введя «exit»" << endl;
            }
        } while (!IsValidInput(number));

        while (number.find('.') == string::npos) {
            number = ReplaceRule(number, rules);
        }

        number.replace(number.find('.'), 1, "");

        cout << "Результат: " << number << endl;

        string answer;

        cout << "Продолжить - «yes» или «no», выйти из программы - «exit»." << endl;

        do {
            cout << "Введите действие: ";
            cin >> answer;

            if (!IsValidAnswer(answer)) {
                cout << "Неправильный ввод, повторите заново или выйдите из программы, введя «exit»" << endl;
            }
        } while (!IsValidAnswer(answer));

        if (answer == "no") {
            is_active = false;
        } else if (answer == "exit") {
            return 0;
        }
    }

    return 0;
}

string ReplaceRule(string number, vector<pair<string, string>> rules) {
    for (int i = 0; i < rules.size(); i++) {
        pair<string, string> rule = rules[i];

        size_t pos = number.find(rule.first);

        if (pos != string::npos) {
            string previous = number, highlighted = number;

            number.replace(pos, rule.first.length(), rule.second);
            highlighted.replace(pos, rule.first.length(), "\033[1;31m" + rule.first + "\033[0m");

            cout << '(' << i + 1 << ')' << ' ';
            cout << highlighted << " -> " << number << endl;

            break;
        }
    }

    return number;
}

bool IsValidInput(string input) {
    bool is_beginning = true;

    for (int i = 0; i < input.size(); i++) {
        if (is_beginning && input[i] == '0' && input.size() > 1) {
            return false;
        }

        if (input[i] != '0' && input[i] != '1' && input[i] != '2' && input[i] != '3') {
            return false;
        } else if (input[i] != '0') {
            is_beginning = false;
        }
    }

    return true;
}

bool IsValidAnswer(string answer) {
    return answer == "yes" || answer == "no" || answer == "exit";
}
