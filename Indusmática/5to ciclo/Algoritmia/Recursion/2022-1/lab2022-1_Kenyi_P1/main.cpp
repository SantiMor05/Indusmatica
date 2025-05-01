/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: kenyi
 *
 * Created on 30 de abril de 2025, 10:02 PM
 */

#include <iostream>
#define M 6
using namespace std;

/*
 * 
 */

void colocarAnaqueles(int matriz[][M], int &P, int F, int C) {

    if (P <= 0 or F >= M)return;
    int centro = C / 2.0 - F;
    int fin = C / 2.0 + F;
    if (M % 2 == 0) centro--;
    for (int i = centro; i <= fin; i++) {
        if (P > 0 and matriz[F][i] == 0) {
            matriz[F][i] = 5;
            P--;
        }
    }
    colocarAnaqueles(matriz, P, F + 1, C);

}

int main(int argc, char** argv) {
    int F = 6, C = 6, P = 27;
    int matriz [][M] = {
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0},
        {0, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 0}
    };
    int p_ini = P;
    colocarAnaqueles(matriz, P, 0, C);
    cout << "Se colocaron: " << p_ini - P << " anaqueles" << endl;
    if (P != 0) cout << "Faltaron: " << P << " anaqueles" << endl;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }

    if (P == 0)cout << "Si es posible ordenar los producto en el anaquel";
    else cout << "No es posible ordenar los producto en el anaquel";


    return 0;
}

