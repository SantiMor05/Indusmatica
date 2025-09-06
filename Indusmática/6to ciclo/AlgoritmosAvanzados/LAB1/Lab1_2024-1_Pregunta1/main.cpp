#include <iostream>
#include <cmath>
using namespace std;
#define K 4

int y = 0;

int estados[]{1, 1, 1, 1, 1, 1};

bool validarK(int *arr, int m) {
    int ant = 0;
    for (int i = 0; i <= m; i++) {
        if (arr[i] != 0) {
            if (estados[i]==0) return false;
            if (ant == 0) {
                ant = arr[i];
            } else {
                if (abs(arr[i] - ant) > K) return false;
                else ant = arr[i];
            }
        }
    }
    return true;
}

int pedidosAtender(int *arr, int pos, int cant, int peso, int *arrSol, int m) {
    if (peso < 0 or cant == pos) {
        return 0;
    }
    if (estados[pos] == 1)
        arrSol[m] = arr[pos];
    else return pedidosAtender(arr, pos + 1, cant, peso, arrSol, m + 1);
    if (arr[pos] == peso) {
        if (validarK(arrSol, m)) {
            cout << "Resultado:";
            for (int i = 0; i < m + 1; i++) {
                if (arrSol[i] != 0) {
                    cout << arrSol[i] << " ";
                    estados[i] = 0;
                }
            }
            cout << endl;
            y++;
        }
    }
    if (pedidosAtender(arr, pos + 1, cant, peso - arr[pos], arrSol, m + 1)) {
        return 1;
    } else {
        arrSol[m] = 0;
        return pedidosAtender(arr, pos + 1, cant, peso, arrSol, m + 1);
    }
}

int main() {
    int arrPaq[] = {2, 8, 9, 6, 7,6};
    int n = sizeof(arrPaq) / sizeof(arrPaq[0]);
    int peso = 15;
    int arrSol[n]{};

    pedidosAtender(arrPaq, 0, n, peso, arrSol, 0);
    cout << "se puede atender: " << y << endl;
    return 0;
}
