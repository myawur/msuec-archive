#include <iostream>

using namespace std;

const int kMaxElements = 2010;
const int kMaxNumber = 1000;

int counter[kMaxElements], numbers[kMaxElements];

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;

        a += kMaxNumber;

        counter[a]++;
        numbers[a] = 1;
    }

    int max_count = 0;
    for (int i = 0; i < kMaxElements; i++) {
        max_count = max(max_count, counter[i]);
    }

    cout << max_count << endl;

    for (int i = 0; i < kMaxElements; i++) {
        if (counter[i] == max_count && numbers[i] == 1) {
            cout << i - kMaxNumber << ' ';
        }
    }

    return 0;
}
