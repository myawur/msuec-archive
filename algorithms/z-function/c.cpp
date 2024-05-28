#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> PrefixFunction(string s) {
    int n = s.length();

    vector<int> p(n);

    for (int i = 1; i < n; i++) {
        int j = p[i - 1];

        while (j > 0 && s[i] != s[j]) {
            j = p[j - 1];
        }

        if (s[i] == s[j]) {
            j++;
        }

        p[i] = j;
    }

    return p;
}

int main() {
    // freopen("search.in", "r", stdin);
    // freopen("search.out", "w", stdout);

    string s;
    cin >> s;

    string r = s;
    reverse(r.begin(), r.end());

    vector<int> z = PrefixFunction(s + '#' + r);

    cout << z.back() << endl;

    return 0;
}
