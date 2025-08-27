/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Kenyi
 *
 * Created on 20 de agosto de 2025, 15:19
 */

#include <iostream>
#define MAX 8
#define MAXMOV 8
using namespace std;

int mov[MAX][2];
int tablero[MAX][MAX];

/*
 * 
 */

void matrizMov() {
    mov[0][0] = -2;
    mov[0][1] = 1;
    mov[1][0] = -1;
    mov[1][1] = 2;
    mov[2][0] = 1;
    mov[2][1] = 2;
    mov[3][0] = 2;
    mov[3][1] = 1;
    mov[4][0] = 2;
    mov[4][1] = -1;
    mov[5][0] = 1;
    mov[5][1] = -2;
    mov[6][0] = -1;
    mov[6][1] = -2;
    mov[7][0] = -2;
    mov[7][1] = -1;
}

void inicializa() {
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++)
            tablero[i][j] = 0;
    }
}

int esValido(int x, int y) {
    if (x < MAX and y < MAX and x >= 0 and y >= 0 and tablero[x][y] == 0)
        return 1;
    return 0;
}

void imprime() {
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++)
            cout << tablero[i][j] << " ";
        cout << endl;
    }
}

int saltoCaballo(int x, int y, int nmov) {
    
    if (nmov == MAX * MAX + 1) return 1;
    for (int i = 0; i < MAXMOV; i++) {
        int nx = x + mov[i][0];
        int ny = y + mov[i][1];

        if (esValido(nx, ny)) {
            tablero[nx][ny] = nmov;
            if (saltoCaballo(nx, ny, nmov + 1))
                return 1;
            tablero[nx][ny] = 0;
        }
    }
    
    return 0;
}

int main(int argc, char** argv) {
    matrizMov();
    inicializa();
    tablero[0][0] = 1;
    if (saltoCaballo(0, 0, 2))
        imprime();
    return 0;
}

