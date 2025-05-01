/* 
 * File:   main.cpp
 * Author: Farid Oswaldo
 *
 * Created on 30 de abril de 2025, 10:12 PM
 */

#include <iostream>
#include <iomanip>
using namespace std;

/*
 * 
 */

void ordenarAnaqueles(int F, int C, int &P, int M[][6], int nivel) {
    if (nivel >= F) return;
    int centro = C / 2, ini = centro - nivel;
    if (C % 2 == 0) ini--;
    for (int i = ini; i <= centro + nivel; i++) {
        if (M[nivel][i] == 0 && P > 0 && i >= 0 && i < C) {
            M[nivel][i] = 5;
            P--;
        }
        if (P == 0) break;
    }

    for (int i = 0; i < C; i++) {
        cout << M[nivel][i] << ' ';
    }
    cout << endl;
    if (P == 0) cout << "Si es posible ordenar los productos en el anaquel"
            << endl;
    ordenarAnaqueles(F, C, P, M, nivel + 1);

}

int main(int argc, char** argv) {

    int F = 6, C = 6, P = 27;
    int M[6][6] = {
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0},
        {0, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 0}
    };
    
    ordenarAnaqueles(F, C, P, M, 0);


    return 0;
}

