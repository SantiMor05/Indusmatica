/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: kenyi
 *
 * Created on 29 de abril de 2025, 07:09 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;
#define N 5
#define M 5


int solucion[N][M]{};

/*
 * 
 */

void llenarStockTabla(int tabla[][M], int x, int y, int &mayor, ofstream &arch) {

//    if (x >= N or y >= M) return;

    if (tabla[x][y] > mayor)mayor = tabla[x][y];

    if(y+1<M)llenarStockTabla(tabla, x, y + 1, mayor, arch);
    else if(x+1<N)llenarStockTabla(tabla, x + 1, 0, mayor, arch);
    
    
    solucion[x][y] = mayor - tabla[x][y];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++)
            arch << setw(2) << solucion[i][j] << "  ";
        if (i == 0) arch << "Max: " << mayor;
        if (i == 2) arch << "Pos: (" << x << "," << y << ")";
        arch << endl;
    }
    arch << "--------------------------" << endl;
}

int main(int argc, char** argv) {

    ofstream arch("TEXTO.TXT", ios::out);

    int tabla[][M] = {
        {4,3,6,8,7},
        {6,3,8,4,10},
        {2,15,1,2,13},
        {5,1,10,11,2},
        {10,4,7,9,4}
    };

    int mayor = -1;

    llenarStockTabla(tabla,0, 0, mayor, arch);
    cout << "La cantidad maxima es: " << mayor << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++)
            cout << setw(2) << solucion[i][j] << "  ";
        cout << endl;
    }
    return 0;
}

