#include <iostream>
#include <cstring>
using namespace std;

int impComb(int n, string cad, int abre, int cierr) {
    if (cad.size() == 2 * n) {
        cout << cad << endl;
        return 0;
    }
    if (abre < n) {
        cad += '(';
        if (impComb(n, cad, abre + 1, cierr))
            return 1;
        else
            cad.pop_back();
    }

    if (cierr < abre) {
        cad += ')';
        if (impComb(n, cad, abre, cierr + 1))
            return 1;
        else {
            cad.pop_back();
        }
    }
    return 0;
}

int main() {
    int n = 3;
    // int n=4;
    string cad;
    impComb(n, cad, 0, 0);
    return 0;
}
