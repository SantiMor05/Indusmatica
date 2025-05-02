/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: kenyi
 *
 * Created on 2 de mayo de 2025, 05:34 PM
 */

#include <iostream>

using namespace std;
#define N 6

/*
 * 
 */


void encontrarRutaMayor(int matriz[][N], int x, int y, int fil, int col,
        int &ruta_mayor, int ruta, int &camino_mayor, int camino) {
    if (x >= fil or y >= col or col==1)return;
    ruta += matriz[x][y];
    if (ruta >= ruta_mayor) {
        ruta_mayor = ruta;
        camino_mayor = camino;
    }
    //mueve derecha
    encontrarRutaMayor(matriz, x, y + 1, fil, col, ruta_mayor, ruta, camino_mayor, camino);
    if (y == col - 1 and x + 1 != fil)
        encontrarRutaMayor(matriz, x + 1, y, fil, col, ruta_mayor, ruta, camino_mayor, camino);
    else encontrarRutaMayor(matriz, x + 1, 0, fil, col - 1, (ruta_mayor), 0, camino_mayor, camino + 1);

}

int main(int argc, char** argv) {
    int matriz[][N] = {
        {1, 2, 9, 1, 2, 3},
        {5, 1, 7, 9, 2, 1},
        {0, 7, 0, 3, 8, 1},
        {1, 2, 6, 1, 2, 2},
        {0, 6, 9, 5, 0, 5},
        {100, 40, 4, 1000, 119, 0}
    };

    //    int matriz[][N] = {
    //        {0, 0, 0},
    //        {0, 0, 0},
    //        {10, 6, 3}
    //    };

    int ruta_mayor = 0;
    int camino_mayor = 1;
    encontrarRutaMayor(matriz, 0, 0, N, N, ruta_mayor, 0, camino_mayor, 1);
    cout << "La ruta con mayor paquetes es el camino " << camino_mayor
            << " que contienes " << ruta_mayor;
    return 0;
}

