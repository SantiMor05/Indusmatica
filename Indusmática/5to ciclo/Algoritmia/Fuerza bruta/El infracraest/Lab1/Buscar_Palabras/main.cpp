/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
/* 
 * File:   main.cpp
 * Author: esteban
 *
 * Created on 31 de marzo de 2025, 10:27
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#define N 5
//matriz de movimiento
int mov[8][2];
//es de menara general 
using namespace std;

void buscapupi(char tabla[][N],char *palabraBuscada,int m);
int busca(char tabla[][N],char *palabraBuscada,int i,int k,int m);


void movimientos(){
    //Primer movimiento
    mov[0][0]=-1; mov[0][1]=0;
    //Segundo movimiento
    mov[1][0]=-1; mov[1][1]=1;
    //Tercer movimiento
    mov[2][0]=0; mov[2][1]=1;
    //Cuarto movimiento
    mov[3][0]=1; mov[3][1]=1;
    //Primer movimiento
    mov[4][0]=1; mov[4][1]=0;
    //Primer movimiento
    mov[5][0]=1; mov[5][1]=-1;
    //Primer movimiento
    mov[6][0]=0; mov[6][1]=-1;
    //Primer movimiento
    mov[7][0]=-1; mov[7][1]=-1;
}


/*
 * 
 */
int main(int argc, char** argv) {
    char tabla[][N] = {
        {'H', 'I', 'J', 'O', 'F'},
        {'U', 'R', 'S', 'O', 'L'},
        {'B', 'I', 'C', 'A', 'L'},
        {'G', 'R', 'A', 'S', 'O'},
        {'T', 'R', 'I', 'C', 'A'},
    };
    char palabraBuscada[]={'S','O','L'};
    //Hsy q definir una matriz de los movimientos
    int m=3;
    
    movimientos();
    buscapupi(tabla,palabraBuscada,m);
    
    return 0;
}

void buscapupi(char tabla[][],char *palabraBuscada,int m){
    for (int i = 0; i < N; i++) {
        for (int k = 0; k < N; k++) {
            busca(tabla,palabraBuscada,i,k,m);
        }

    }

}

int busca(char tabla[][N],char *palabraBuscada,int x,int y,int m){
    //Si la letra no es igual a la palabra no ha necesidad de buscar
    if(tabla[x][y]!=palabraBuscada[0]) return 0;
    
    for (int i = 0; i < 8; i++) {
        int nx=x+mov[i][0];
        int ny=y+mov[i][1];
        
        //Aplicamos la restricciones por si se sale de la matriz
        if (not()) {

        }

        
    }

    
}

