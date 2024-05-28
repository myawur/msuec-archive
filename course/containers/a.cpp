#include <deque>
#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    deque<int> d;

    int min_number = INT_MAX, min_index = 0;
    int max_number = INT_MIN, max_index = 0;

    for (int i = 1; i <= n; i++) {
        int number;
        cin >> number;

        if (min_number > number) {
            min_number = number;
            min_index = i;
        }
        if (max_number < number) {
            max_number = number;
            max_index = i;
        }

        d.push_back(number);
    }

    if (!d.size()) {
        cout << "No numbers" << endl;
        return 0;
    }

    cout << min_number << ' ' << min_index << endl;
    cout << max_number << ' ' << max_index << endl;

    return 0;
}
