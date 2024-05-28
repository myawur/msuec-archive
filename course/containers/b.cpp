#include <fstream>
#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    map<int, string> mpS;
    // map<int, string>::iterator itS;
    ifstream inS("input.txt");
    ofstream outS("output.txt");

    int n;
    inS >> n;

    int tmp1;
    string tmp2;

    while (n--) {
        inS >> tmp1 >> tmp2;
        mpS.emplace(tmp1, tmp2);
    }

    int m;
    inS >> m;
    while (m--) {
        inS >> tmp1;

        if (mpS[tmp1] == "") {
            outS << "No" << endl;
        } else {
            outS << mpS[tmp1] << endl;
        }
    }

    inS.close();
    outS.close();

    return 0;
}
