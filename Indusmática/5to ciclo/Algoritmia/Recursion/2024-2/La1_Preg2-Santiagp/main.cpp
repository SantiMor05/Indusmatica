/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: santi
 *
 * Created on 22 de abril de 2025, 16:11
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

#define N 5
#define M 5


int solucion[N][M]{};


/*
 * 
 */


int calcularProductosAReponer(int fil,int col, int max, int tablero[][M]);

int main(int argc, char** argv) {
    
    int tablero[N][M] = {
        {4,3,6,8,7},
        {6,3,8,4,10},
        {2,15,1,2,13},
        {5,1,10,11,2},
        {10,4,7,9,4}
    };
    int max = -1;
    calcularProductosAReponer(0,0,max,tablero);

    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++)
            cout << setw(3) << solucion[i][j];
        cout << endl;
    }
    
    return 0;
}

int calcularProductosAReponer(int fil,int col,int max, int tablero[][M]){

    if(max < tablero[fil][col])
        max = tablero[fil][col];
    
    int maxLocal;
    
    if(col + 1  < M)
        maxLocal = calcularProductosAReponer(fil, col + 1,max,
                tablero);
    else if(fil + 1 < N)
        maxLocal = calcularProductosAReponer(fil + 1, 0,max,
                tablero);
    if(max < maxLocal)
        max =  maxLocal;
    solucion[fil][col] = max - tablero[fil][col];
    
    return max;
}

