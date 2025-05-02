/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: santi
 *
 * Created on 1 de mayo de 2025, 17:21
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

/*
 * 
 */

#define F 6
#define C 6


void ordenarAnaqueles(int fil, int colIzq, int colDer, int filaFin, 
        int colFin, int P, int &cont, int tablero[][C]){
    
    if(fil >=filaFin or  fil < 0)
        return;
    
    for(int i = 0; i < colFin; i++){
        if(tablero[fil][i] != 1 and cont != P and i >= colIzq and i <=colDer){
            cont++;
            tablero[fil][i] = 5;
        }   
        cout << tablero[fil][i] << " ";
    }
    cout << endl;
    if(colIzq - 1 >= 0 and colDer + 1 < colFin)
        ordenarAnaqueles(fil + 1, colIzq - 1, colDer + 1, F, C, P, cont, tablero);
    else
        ordenarAnaqueles(fil + 1, 0, colFin - 1, F, C, P, cont, tablero);
    
    
    if(cont == P and fil == 0){
        cout << "Si es posible ordenar los productos" << endl;
        return;
    }
    else if (fil == 0){
        cout << "No es posible utilizar este anaquel para la cantidad de "
                "productos solicitados" << endl;
    }
    
}


int main(int argc, char** argv) {
    
    int P = 27;
    int M[F][C]{
        {0,0,0,0,0,0},  
        {0,0,0,0,0,0},  
        {0,0,0,1,0,0},  
        {0,1,0,0,0,0},  
        {0,0,0,0,1,0},  
        {0,0,0,0,0,0}  
    };
    int medio = C / 2;
    int resto = C % 2, cont = 0;
    
    if(resto == 1)resto = 0;
    else resto = 1;
    
    ordenarAnaqueles(0, medio - resto, medio, F, C, P, cont, M);
    
    //Da flojera hacer el item b

    return 0;
}

