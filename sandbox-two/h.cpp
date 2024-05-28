#include <algorithm>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

void solve() {
    string s;
    cin >> s;

    int n = s.size();

    s += s;

    vector<vector<int>> v(26);
    for (int i = 0; i < n; i++) {
        v[s[i] - 'a'].push_back(i);
    }

    double result = 0;
    for (int first_symbol = 0; first_symbol < 26; first_symbol++) {
        double a = 0;
        for (int i = 0; i < n; i++) {
            vector<int> u(26);
            for (int j : v[first_symbol]) {
                u[s[j + i] - 'a']++;
            }

            int size = v[first_symbol].size();
            int count = 0;

            for (int second_symbol = 0; second_symbol < 26; second_symbol++) {
                if (u[second_symbol] == 1) count++;
            }

            a = max(a, (double)count / size);
        }
        result += (double)(v[first_symbol].size()) / n * a;
    }

    cout << fixed << setprecision(20) << result << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}