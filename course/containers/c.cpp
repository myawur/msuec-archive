#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Author {
   public:
    int NN = 0;
    string firstname = "";
    string lastname = "";
    int yearBirth = 0;
    int yearDeath = 0;
    Author(int n, string fn, string ln, int yB, int yD) {
        NN = n;
        firstname = fn;
        lastname = ln;
        yearBirth = yB;
        yearDeath = yD;
    }
};

int main() {
    vector<Author> vecP;
    vector<Author>::iterator itvP;
    ifstream inP("input.txt");

    string tmp2, tmp3;
    int tmp1, tmp4, tmp5;
    while (inP >> tmp1 >> tmp2 >> tmp3 >> tmp4 >> tmp5) {
        Author buf(tmp1, tmp2, tmp3, tmp4, tmp5);
        vecP.push_back(buf);
    }

    double total_age = 0;
    int count = 0;

    int oldest_index = 0, min_year = INT_MAX;

    for (itvP = vecP.begin(); itvP != vecP.end(); ++itvP) {
        total_age += ((*itvP).yearDeath - (*itvP).yearBirth);
        count++;

        if ((min_year > (*itvP).yearBirth) || (min_year == (*itvP).yearBirth && oldest_index > (*itvP).NN)) {
            min_year = (*itvP).yearBirth;
            oldest_index = (*itvP).NN;
        }

        // cout << (*itvP).NN << " " << (*itvP).firstname << " " << (*itvP).lastname << " " << (*itvP).yearBirth << " " << (*itvP).yearDeath << endl;
    }

    cout << (int)total_age / count << endl;

    for (itvP = vecP.begin(); itvP != vecP.end(); ++itvP) {
        if ((*itvP).NN == oldest_index) {
            cout << (*itvP).firstname << " " << (*itvP).lastname << " " << (*itvP).yearBirth << endl;
        }
    }

    return 0;
}
