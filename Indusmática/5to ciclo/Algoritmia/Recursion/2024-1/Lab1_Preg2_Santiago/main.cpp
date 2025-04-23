/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: santi
 *
 * Created on 22 de abril de 2025, 16:33
 */

#include <iostream>
#include <iomanip>

using namespace std;

#define N 6
#define M 6

/*
 * 
 */

int tablero[N][M] ={
    {0,0,0,1,0,1},
    {0,0,1,0,0,0},
    {0,1,0,0,0,1},
    {1,0,0,0,0,0},
    {0,1,0,0,1,0},
    {0,0,0,0,1,0}
};

int contarUnidades(int filaIni, int filaFin, int colIni,
        int colFin);

int main(int argc, char** argv) {
    
    
    int fila = 4, col = 4;
    int unidades = contarUnidades(fila, fila, col,col);

    cout << "El resultado de la busqueda sera: " << unidades << " unidades" <<
            endl;
    
    return 0;
}

int contarUnidades(int filaIni, int filaFin, int colIni,
        int colFin){
    
    int unidades = 0;
    
    if(filaIni < 0 or filaFin >= N or colIni < 0 or colFin >=M)
        return 0;
    
    if(tablero[filaIni][colIni]==1)
        unidades++;
    if(filaIni != filaFin){
        for(int i = colIni + 1; i < colFin; i++)
        if(tablero[filaIni][i]==1)
            unidades++;
        for(int i = filaIni; i <= filaFin; i++){
            if(tablero[i][colFin]==1)
                unidades++;
        }
        for(int i = colIni; i < colFin; i++)
            if(tablero[filaFin][i]==1)
                unidades++;
        for(int i = filaIni + 1; i < filaFin; i++)
            if(tablero[i][colIni]==1)
                unidades++;
    }
    
    unidades += contarUnidades(filaIni - 1, filaFin + 1, colIni -1, colFin + 1);
   
    return unidades;
}