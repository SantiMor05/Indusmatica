/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: santi
 *
 * Created on 21 de mayo de 2025, 12:33
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>

#define N 3
#define M 3

using namespace std;

/*
 * 
 */

void colorea(int fil,int col,int antColor, int nuevoColor, int tablero[][M]){
    
    if(fil < 0 or col < 0 or fil == N or col == M) return;
    
    if(tablero[fil][col] == antColor){
        tablero[fil][col] = nuevoColor;
        //Coloreamos abajo
        colorea(fil + 1, col, antColor, nuevoColor, tablero);
        //Coloreamos arriba
        colorea(fil - 1, col, antColor, nuevoColor, tablero);
        //Coloreamos derecha
        colorea(fil, col + 1, antColor, nuevoColor, tablero);
        //Coloreamos izquierda
        colorea(fil, col - 1, antColor, nuevoColor, tablero);
    }
    
}


int main(int argc, char** argv) {
    
    int x = 0, y = 0, nuevoColor = 2;
    
    int tablero[N][M]{
        {1,1,1},
        {1,1,0},
        {1,0,1}
    };
    if(x < 0 or y < 0 or y >= M or x >= N)
        cout << "Fuera del rango" << endl;
    else
        colorea(x,y,tablero[x][y], nuevoColor, tablero);
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++)
            cout << tablero[i][j] << " ";
        cout << endl;
    }
    
    return 0;
}

