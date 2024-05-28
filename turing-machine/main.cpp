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

#include "../static-lib/library.cpp"

int main() {
    setlocale(LC_ALL, "Russian");

    bool is_active = true;
    while (is_active) {
        string input;
        do {
            cout << "Введите троичное число: ";
            cin >> input;

            if (input == "exit") {
                return 0;
            }

            if (!IsValidInput(input)) {
                cout << "Неправильный ввод, повторите заново или выйдите из программы, введя \033[31m«exit»\033[0m." << endl;
            }
        } while (!IsValidInput(input));

        // Machine machine;

        // InitializeTransitions(machine.transitions);
        // SetAlphabet(machine.alphabet);

        // machine.transition_count = machine.transitions.size();
        // machine.tape.number = ' ' + input + ' ';

        // Convert(machine);
        // PrintResult(machine.tape.number, machine.tape.index);
        
        // TODO: почему в начале слова остается пробел?
        // TODO: я убрал пробел перед выводом ленты, но это костыль
        // cout << "Результат: " << machine.tape.number << endl;

        Initialize(input);

        string answer;
        cout << "Продолжить - \033[32m«yes»\033[0m, выйти из программы - \033[31m«exit»\033[0m." << endl;
        do {
            cout << "Введите действие: ";
            cin >> answer;

            if (!IsValidAnswer(answer)) {
                cout << "Неправильный ввод, повторите заново." << endl;
            }
        } while (!IsValidAnswer(answer));
        if (answer == "exit") {
            is_active = false;
        }
    }

    return 0;
}
