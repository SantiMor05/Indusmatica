/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Usuario
 *
 * Created on 21 de abril de 2025, 18:01
 */

#include <iostream>

using namespace std;
#define N 6
#define M 6

int robot_sonda(int tabla[][M],int x,int y,int n, int m, int contarCentro){
    int cont = 0;
    if (x<0 or y<0 or x>=N or y>=M or n>=N or m>=M) return 0;
    if (contarCentro){
        cont += tabla[x][y];
        cont += robot_sonda(tabla,x-1,y-1,n+1,m+1,0);
    }else{
        for (int i = y; i <= m; i++) cont += tabla[x][i];
        for (int i = x+1; i <= n; i++) cont += tabla[i][m];
        for (int i = m-1; i >= y; i--) cont += tabla[n][i];
        for (int i = n-1; i > x; i--) cont += tabla[i][y];
        cont += robot_sonda(tabla,x-1,y-1,n+1,m+1,0);
    }
    return cont;
}

int main(int argc, char** argv) {
    int tabla[N][M] = {         {0,0,0,1,0,1},
                                {0,0,1,0,0,0},
                                {0,1,0,0,0,1},
                                {1,0,0,0,0,0},
                                {0,1,0,0,1,0},
                                {0,0,0,0,1,0}};
    int x=4,y=4;
    cout<<robot_sonda(tabla,x,y,x,y,1);
    return 0;
}

