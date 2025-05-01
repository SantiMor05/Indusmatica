/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: kenyi
 *
 * Created on 30 de abril de 2025, 10:51 PM
 */

#include <iostream>
#include <climits>
using namespace std;
#define N 9
#define M 5

/*
 * 
 */

int mov[][2] = {
    {-1, -1},
    {-1, 0},
    {-1, 1},
    {0, 1},
    {1, 1},
    {1, 0},
    {1, -1},
    {0, -1}
};

char campoMin[][M] = {
    {' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' '}
};

void detectarMina(char campo[][M], int x, int y) {
    int nx, ny;
    for (int i = 0; i < 8; i++) {
        nx = x + mov[i][0];
        ny = y + mov[i][1];
        if (nx >= 0 && nx < N && ny >= 0 && ny < M && campo[nx][ny] == '*') {
            campoMin[nx][ny] = '*';
        }
    }
}

void recorrerCampo(char campo[][M], int x, int y, int pasos, int &minPasos) {

    if (x >= N || y >= M || campo[x][y] == '*') return;

    // Si llegamos al destino, actualizar mínimo
    if (x == N - 1 && y == M - 1) {
        if (pasos < minPasos) minPasos = pasos;
        return;
    }

    detectarMina(campo, x, y);

    // Moverse a la derecha
    recorrerCampo(campo, x, y + 1, pasos + 1, minPasos);
    // Moverse hacia abajo
    recorrerCampo(campo, x + 1, y + 1, pasos + 1, minPasos);
    recorrerCampo(campo, x + 1, y, pasos + 1, minPasos);
    // Moverse hacia diagonal
}

int main(int argc, char** argv) {
    //    char campo[][M] = {
    //        {' ', ' ', ' '},
    //        {' ', '*', ' '},
    //        {'*', ' ', ' '},
    //        {'*', ' ', ' '},
    //    };

    char campo[][M] = {
        {' ', ' ', ' ', ' ', '*'},
        {' ', ' ', ' ', ' ', ' '},
        {' ', ' ', '*', ' ', ' '},
        {' ', ' ', ' ', ' ', ' '},
        {' ', '*', '*', ' ', '*'},
        {' ', '*', '*', ' ', '*'},
        {'*', '*', ' ', '*', ' '},
        {'*', '*', '*', '*', ' '},
        {'*', ' ', ' ', ' ', ' '}
    };

    int min_pasos = INT_MAX;
    recorrerCampo(campo, 0, 0, 0, min_pasos);
    if (min_pasos == INT_MAX) {
        cout << "No es posible llegar al punto final\n";
    } else {
        cout << "Mínimo número de pasos: " << min_pasos << endl;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << "(" << campoMin[i][j] << ") ";
        }
        cout << endl;
    }
    return 0;
}

