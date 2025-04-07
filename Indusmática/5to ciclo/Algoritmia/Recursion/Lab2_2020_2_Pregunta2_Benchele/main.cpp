/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Lenovo
 *
 * Created on 7 de abril de 2025, 04:42 PM
 */

#include <cstdlib>
#include <iostream>
#include <cmath>
#include <climits>
#define N 6
#define M 6

using namespace std;

int mapa[][M] = {{0,0,0,1,0,1},
                 {0,0,1,0,0,0},
                 {0,1,0,0,0,1},
                 {1,0,0,0,0,0},
                 {0,1,0,0,0,0},
                 {0,0,0,0,1,0}};
int mov[4][2];

void movimientos(){
    mov[0][0] = -1; mov[0][1] = 0; //Arriba
    mov[1][0] = 0; mov[1][1] = 1; //Derecha
    mov[2][0] = 1; mov[2][1] = 0; //Abajo
    mov[3][0] = 0 ; mov[3][1] = -1; //IZquierda
}

int sonda(int x, int y, int mov_x, int mov_y, int flag_x, int flag_y){
    int contador = 0;
    //Caso base
    if(N <= x or N <= y or x < 0 or y < 0)return 0;
    if(not(flag_x) and not(flag_y) and mapa[x][y])contador++;
    if(not(flag_x)){ //Recorre verticalmente
        for (int i = 0; i < x; i++) contador += mapa[i][y];
        for (int i = x + 1; i < N; i++) contador += mapa[i][y];
    }
    if(not(flag_y)){ //Recorre horizontalmente
        for (int i = 0; i < y; i++) contador += mapa[x][i];
        for (int i = y + 1; i < M; i++) contador += mapa[x][i];
    }
    contador += sonda(x + mov_x, y + mov_y, mov_x, mov_y, mov_x, mov_y);
    return contador;
}
/*
 * 
 */
int main(int argc, char** argv) {
    int x = 3, y = 2;
    movimientos();
    //cout<<mov[3][0]<<" : "<<mov[2][1]<<endl;
    cout<< "La suma es: "<< sonda(x, y, mov[1][0], mov[1][1], 0,0);
    return 0;
}

