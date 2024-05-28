/** @cond */
/**
 * ЮФУ, ИКТИБ, МОП ЭВМ
 * Программирование и основы теории алгоритмов
 * Индивидуальное задание
 * Проектирование и реализация машины Тьюринга
 * Вариант №10.1
 * Кожемякин Ярослав Дмитриевич (КТбо1-7)
 * 18.05.2024
 */
 /** @endcond */

#include "library.h"

#include <algorithm>
#include <clocale>
#include <fstream>
#include <iostream>

/**
 * @brief Глобальная переменная, представляющая машину Тьюринга.
 *
 * Эта переменная используется для представления машины Тьюринга в программе.
 * Она может быть доступна из любой части программы.
 */
Machine machine;

bool SetTransitions() {
    ifstream fin("transitions.txt");

    // for (int i = 0; i < kTransitionsCount; i++) {
    //     int index, to;
    //     char symbol, replacement, action;
    //     fin >> index >> symbol >> replacement >> action >> to;

    //     transitions[index][symbol] = {replacement, action, to};
    // }

    if (!fin.is_open()) {
        return false;
    }

    int index, to;
    char symbol, replacement, action;
    int count = 0;
    while (fin >> index >> symbol >> replacement >> action >> to) {
        count++;
        machine.transitions.resize(count + 1);
        machine.transitions[index][symbol] = { replacement, action, to };
    }

    fin.close();

    return true;
}

bool SetAlphabet() {
    ifstream fin("alphabet.txt");

    if (!fin.is_open()) {
        return false;
    }

    string input;
    fin >> input;
    for (int i = 0; i < input.size(); i++) {
        machine.alphabet.insert(input[i]);
    }

    fin.close();

    return true;
}

void Initialize(string input) {
    bool are_transitions_loaded = SetTransitions();
    bool is_alphabet_loaded = SetAlphabet();

    if (!are_transitions_loaded) {
        cout << "Не получилось загрузить файл с переходами машины Тьюринга! (transitions.txt)" << endl;
    }
    if (!is_alphabet_loaded) {
	cout << "Не получилось загрузить файл с алфавитом машины Тьюринга! (alphabet.txt)" << endl;
    }

    if (are_transitions_loaded && is_alphabet_loaded) {
        machine.transition_count = machine.transitions.size();
        machine.tape.number = ' ' + input + ' ';

        Convert();
        PrintResult();
    }
}

void PrintConfiguration(string before, int previous_index, int previous_transition) {
    string after = machine.tape.number;
    int current_index = machine.tape.index;

    for (int i = 0; i < before.size(); i++) {
        if (before[i] == ' ') {
            before[i] = '_';
        }

        if (i == previous_index) {
            cout << "\033[31m" << before[i] << "\033[0m";
        }
        else {
            cout << before[i];
        }
    }

    cout << " -> ";

    for (int i = 0; i < after.size(); i++) {
        if (after[i] == ' ') {
            after[i] = '_';
        }

        if (i == previous_index) {
            cout << "\033[32m" << after[i] << "\033[0m";
        }
        else {
            cout << after[i];
        }
    }
    
    cout << " (";
    cout << "Q\033[31m" << previous_transition << "\033[0m";
    cout << " -> ";
    cout << "Q\033[32m" << machine.tape.transition << "\033[0m";
    cout << ")" << endl;
}

void PrintResult() {
    string number = machine.tape.number;
    cout << "Результат: ";
    for (int i = 0; i < number.size(); i++) {
        if (number[i] == ' ') {
            number[i] = '_';
        }

        if (i == machine.tape.index) {
            cout << "\033[33m" << number[i] << "\033[0m";
        }
        else {
            cout << number[i];
        }
    }
    cout << endl;
}

bool IsValidInput(string input) {
    bool is_beginning = true;

    for (int i = 0; i < input.size(); i++) {
        if (is_beginning && input[i] == '0' && input.size() > 1) {
            return false;
        }

        if (input[i] != '0' && input[i] != '1' && input[i] != '2') {
            return false;
        }
        else if (input[i] != '0') {
            is_beginning = false;
        }
    }

    return true;
}

bool IsValidAnswer(string answer) {
    return answer == "yes" || answer == "exit";
}

bool IsValidByAlphabet(string input) {
    for (int i = 0; i < input.size(); i++) {
        if (machine.alphabet.count(input[i]) <= 0) {
            return false;
        }
    }

    return true;
}

void MoveHead(char action) {
    if (action == '>') {
        machine.tape.index++;
    }
    else if (action == '<') {
        machine.tape.index--;
    }
}

void Step() {
    if (machine.tape.index < 0) {
        machine.tape.number = '_' + machine.tape.number;
        machine.tape.index++;
    }
    else if (machine.tape.index >= machine.tape.number.size()) {
        machine.tape.number += '_';
    }

    char symbol = machine.tape.number[machine.tape.index];
    if (symbol == ' ' || machine.tape.index >= machine.tape.number.size()) {
        symbol = '_';
    }
    Transition transition = machine.transitions[machine.tape.transition][symbol];

    string previous_number = machine.tape.number;
    if (machine.tape.index < machine.tape.number.size()) {
        machine.tape.number[machine.tape.index] = transition.replacement;
    }
    else {
        machine.tape.number += transition.replacement;
    }
    int previous_transition = machine.tape.transition;
    machine.tape.transition = transition.to;

    int previous_index = machine.tape.index;
    MoveHead(transition.action);

    PrintConfiguration(previous_number, previous_index, previous_transition);
}

void Convert() {
    machine.tape.index = 1, machine.tape.transition = 1;
    while (machine.tape.transition) {
        Step();
    }
}
