/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Usuario
 *
 * Created on 22 de mayo de 2025, 09:31
 */

#include <cstdlib>
#include <iostream>
using namespace std;
#define N 6
#define M 7

/*
 * 
 */

void paint(int matriz[][M],int x,int y,int nuevoColor, int antColor){
    if (x<0 or y<0 or x>=N or y>=M) return;
    if (matriz[x][y]==nuevoColor) return;
    else if (matriz[x][y]==antColor){
        matriz[x][y] = nuevoColor;
        paint(matriz,x+1,y,nuevoColor,antColor);
        paint(matriz,x,y+1,nuevoColor,antColor);
        paint(matriz,x-1,y,nuevoColor,antColor);
        paint(matriz,x,y-1,nuevoColor,antColor);
    }
}

int main(int argc, char** argv) {
    int matriz[][M] = {                 {1,1,1,0,1,1,0},
                                        {1,1,0,1,1,1,1},
                                        {1,0,1,3,3,3,1},
                                        {1,1,1,4,3,3,2},
                                        {0,1,0,0,0,0,0},
                                        {1,1,2,4,5,4,5}};
    int x, y, nuevoColor, antColor;
    cout<<"Ingrese el color a cambiar y el nuevo color: ";
    cin>>antColor>>nuevoColor;
    cout<<"Ingrese la posición a rellenar con pintura: ";
    cin>>x>>y;
    paint(matriz,x,y,nuevoColor,antColor);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout<<matriz[i][j]<<"  ";
        }
        cout<<endl;
    }

    return 0;
}

