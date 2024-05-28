#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> ZFunction(string s) {
    int n = s.size();

    vector<int> z(n);

    int l = 0, r = 0;

    for (int i = 1; i < n; i++) {
        if (i < r) {
            z[i] = min(r - i, z[i - l]);
        }
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if (i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }

    return z;
}

int main() {
    freopen("basis.in", "r", stdin);
    freopen("basis.out", "w", stdout);

    string s;
    cin >> s;

    vector<int> z = ZFunction(s);

    for (int i = 1; i < z.size(); i++) {
        if (z[i] + i == s.size()) {
            cout << i << endl;
            return 0;
        }
    }

    cout << s.size() << endl;

    return 0;
}
