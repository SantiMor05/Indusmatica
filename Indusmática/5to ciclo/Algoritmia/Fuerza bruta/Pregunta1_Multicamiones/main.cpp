/* 
 * File:   main.cpp
 * Author: Farid Oswaldo
 *
 * Created on 30 de marzo de 2025, 11:03 AM
 */

#include <iostream>
#include <iomanip>
using namespace std;
#include <cmath>

/*
 * 
 */

void cargaBin(int num, int base, int *cromo, int n) {
    int rest, i = 0;
    for (int j = 0; j < n; j++) cromo[j] = 0; // inicializar en 0
    while (num > 0) {
        rest = num % base;
        num /= base;
        cromo[i] = rest;
        i++;
    }
}

void calcularMaxYMin(int *capacAux, int m, int &max, int &min) {
    for (int i = 0; i < m; i++) {
        if (capacAux[i] < min) min = capacAux[i];
        if (capacAux[i] > max) max = capacAux[i];
    }

}

int main(int argc, char** argv) {

    int m = 4, n = 5, opcion, base = m + 1;
    int cromo[n];
    int paquete[n] = {50, 20, 30, 50, 20};
    int capac[m] = {25, 50, 100, 100};
    int capacAux[n], min, max, dif = 99999, mcomb;
    bool siVale;
    opcion = (int) pow(base, n);

    for (int i = 0; i < opcion; i++) {
        cargaBin(i, base, cromo, n);
        siVale = true;
        min = 9999;
        max = 0;
        
        for (int k = 0; k < n; k++) capacAux[k] = capac[k];
        for (int j = 0; j < n; j++) {
            capacAux[cromo[j] - 1] -= paquete[j];
            if (capacAux[cromo[j] - 1] < 0 or cromo[j] == 0) {
                siVale = false;
                break;
            }
        }
        
        for (int l = 0; l < n; l++) {
            cout << cromo[l] << ' ';
        }
        calcularMaxYMin(capacAux, m, max, min);
        cout << "min: " << min << "max: " << max << endl;
        
        // Verificar que se usan los todos los camiones
        for (int p = 0; p < m; p++) {
            if(capacAux[p]-capac[p]==0){
                siVale=false;
                break;
            }
        }

        if (siVale and dif > max - min and min >= 0) {
            mcomb = i;
            dif = max - min;
        }
    }
    cargaBin(mcomb, base, cromo, n);
    for (int i = 0; i < n; i++) {
        cout << "Paquete " << i + 1 << " : Camion " << cromo[i] << endl;
    }
    cout << "Diferencia Min: " << dif << endl;
    return 0;
}

