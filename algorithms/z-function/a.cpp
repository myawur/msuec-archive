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
    freopen("search.in", "r", stdin);
    freopen("search.out", "w", stdout);

    string a, b;
    cin >> a >> b;

    vector<int> z = ZFunction(b + '#' + a);

    int count = 0;

    vector<int> r;

    for (int i = 0; i < z.size(); i++) {
        if (z[i] == b.size()) {
            r.push_back(i - b.size());
            count++;
        }
    }

    cout << count << endl;

    for (int i = 0; i < count; i++) {
        cout << r[i] << " ";
    }

    return 0;
}
