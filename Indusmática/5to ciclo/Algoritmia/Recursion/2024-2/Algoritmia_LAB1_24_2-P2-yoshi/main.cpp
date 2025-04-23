/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Usuario
 *
 * Created on 21 de abril de 2025, 17:01
 */

#include <iostream>

using namespace std;
#define N 5
#define M 5

void llenar_tabla(int tabla[][M],int newTabla[][M],int x,int y, int &mayor){
    if (x>=N) return;
    if (tabla[x][y]>mayor) mayor = tabla[x][y];
    if (y+1<M)
        llenar_tabla(tabla,newTabla,x,y+1,mayor);
    else
        llenar_tabla(tabla,newTabla,x+1,0,mayor);
    newTabla[x][y] = mayor - tabla[x][y];
    return;
}



int main(int argc, char** argv) {
    int tabla[N][M] = {             {4,3,6,8,7},
                                    {6,3,8,4,10},
                                    {2,15,1,2,13},
                                    {5,1,10,11,2},
                                    {10,4,7,9,4}};
    int newTabla[N][M]{}, mayor=0;
    llenar_tabla(tabla,newTabla,0,0,mayor);
    cout<<mayor<<endl;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++)
            cout<<newTabla[i][j]<<"  ";
        cout<<endl;
    }
    return 0;
}

