/**
 * ЮФУ, ИКТИБ, МОП ЭВМ
 * Структуры и алгоритмы обработки данных
 * Домашнее задание №3.2
 * Задание F
 * Исполнитель: Кожемякин Ярослав Дмитриевич (КТбо1-7)
 * 19.03.2024
 */

#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    map<string, pair<string, string>> users;  // name, <password, state>

    for (int i = 0; i < n; i++) {
        string command, name, password;
        cin >> command >> name;

        if (command != "logout") {
            cin >> password;
        }

        if (command == "register") {
            if (!users.count(name)) {
                // user not found, success
                users[name] = {password, "registered"};  // state update
                cout << "success: new user added" << endl;
            } else {
                // user found, failure
                cout << "fail: user already exists" << endl;
            }
        } else if (command == "login") {
            if (!users.count(name)) {
                // user not found, failure
                cout << "fail: no such user" << endl;
            } else {
                if (users[name].first != password) {
                    // incorrect password, failure
                    cout << "fail: incorrect password" << endl;
                } else if (users[name].second == "logged in") {
                    // already logged in, failure
                    cout << "fail: already logged in" << endl;
                } else {
                    // not logged in, valid password, success
                    users[name] = {password, "logged in"};  // state update
                    cout << "success: user logged in" << endl;
                }
            }
        } else {
            if (!users.count(name)) {
                // user not found, failure
                cout << "fail: no such user" << endl;
            } else {
                if (users[name].second != "logged in") {
                    // already logged out, failure
                    cout << "fail: already logged out" << endl;
                } else {
                    // not logged out, success
                    users[name] = {users[name].first, "logged out"};  // state update
                    cout << "success: user logged out" << endl;
                }
            }
        }
    }

    return 0;
}
