/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: kenyi
 *
 * Created on 29 de abril de 2025, 06:00 PM
 */

#include <iostream>

using namespace std;
#define M 6
#define N 6

int tablero[N][M] = {
    {0, 0, 0, 1, 0, 1},
    {0, 0, 1, 0, 0, 0},
    {0, 1, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0},
    {0, 1, 0, 1, 1, 1},
    {0, 0, 0, 0, 1, 0}
};

int contarUnidades(int x, int y, int n, int m) {
    int contador = 0;
    if (n<0 or m<0 or x>=N or y>=M or n>=N or m>=M) return 0;

    if (x == n) {
        contador += tablero[x][y];
    } else {
        for (int i = m; i <= y; i++) contador += tablero[n][i];
        for (int i = n+1; i <= x; i++) contador += tablero[i][y];
        for (int i = y-1; i >= m; i--) contador += tablero[x][i];
        for (int i =x-1; i >= n+1; i--) contador += tablero[i][m];
        
    }
    contador += contarUnidades(x + 1, y + 1, n - 1, m - 1);
    return contador;
}

int main(int argc, char** argv) {


    int x = 3, y = 2;
    int contador = contarUnidades(x, y, x, y);

    cout << "El resultado de la busqueda será: " << contador << " unidades" <<
            endl;

    return 0;
}

