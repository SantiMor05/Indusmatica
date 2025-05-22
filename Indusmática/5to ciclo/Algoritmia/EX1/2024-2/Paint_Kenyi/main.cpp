/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: kenyi
 *
 * Created on 21 de mayo de 2025, 06:58 PM
 */

#include <iostream>

using namespace std;
#define N 6

/*
 * 
 */

void pintar(int matriz[][N], int fil, int col, int x, int y, int color, int pixel) {
    if (x >= 0 or y >= 0 or x <= fil or y <= col)return;

    //mover arriba
    matriz[x][y] = color;
    if (matriz[x - 1][y] == pixel and x - 1 >= 0)
        pintar(matriz, fil, col, x - 1, y, color, pixel);
    //mover derecha
    if (matriz[x][y + 1] == pixel and y + 1 < col)
        pintar(matriz, fil, col, x, y + 1, color, pixel);
    //mover izquiera
    if (matriz[x][y - 1] == pixel and y - 1 >= 0)
        pintar(matriz, fil, col, x, y - 1, color, pixel);
    //mover abajo
    if (matriz[x + 1][y] == pixel and x + 1 < fil)
        pintar(matriz, fil, col, x + 1, y, color, pixel);
}

int main(int argc, char** argv) {
    int matriz[][N] = {
        {1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1},
        {1, 1, 0, 1, 1, 1},
        {1, 1, 1, 1, 1, 0},
        {1, 0, 1, 1, 0, 1},
        {1, 1, 1, 0, 1, 1}
    };
    int x = 9, y = 9, color = 2;
    pintar(matriz, N, N, x, y, color, matriz[x][y]);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

