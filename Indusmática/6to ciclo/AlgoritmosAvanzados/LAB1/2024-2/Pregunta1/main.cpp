#include <iostream>

using namespace std;

void imprime(int *arr,int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int cargarack(int ini, int *paquete, int *rack, int n, int m, int *sol) {
    if (ini == n) {
        imprime(sol,m);
        return 0;
    }
    for (int i = 0; i < m; i++) {
        if (rack[i] - sol[i] >= paquete[ini]) {
            sol[i] += paquete[ini];
            if (cargarack(ini + 1, paquete, rack, n, m, sol)) return 1;
            sol[i] -= paquete[ini];
        }
    }

    return 0;
}

int main() {
    int paquete[] = {2, 3, 1, 4};
    int n = sizeof(paquete) / sizeof(int);
    int rack[] = {3, 2, 5, 1, 3};
    int m = sizeof(rack) / sizeof(rack[0]);
    int sol[5]{};
    cargarack(0, paquete, rack, n, m, sol);
    return 0;
}
