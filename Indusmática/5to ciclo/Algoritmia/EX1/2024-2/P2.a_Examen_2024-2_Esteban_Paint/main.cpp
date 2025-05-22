/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
/* 
 * File:   main.cpp
 * Author: esteban
 *
 * Created on 22 de mayo de 2025, 09:11
 */
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#define M 3
#define N 3
/*
 * 
 */

void funcionPaint(int lienzo[][M],int x,int y,int colorNuevo,int colorIni,int n,int m){
    
    // caso base
    if( x<0 or y<0 or x>=n or y>=m) return;
    
    if(lienzo[x][y]==colorIni) lienzo[x][y]= colorNuevo;
    else return;
    //arriba y abajo
    funcionPaint(lienzo,x-1,y,colorNuevo,colorIni,n,m);
    funcionPaint(lienzo,x+1,y,colorNuevo,colorIni,n,m);
    //der e izq
    funcionPaint(lienzo,x,y+1,colorNuevo,colorIni,n,m);
    funcionPaint(lienzo,x,y-1,colorNuevo,colorIni,n,m);
    
}


int main(int argc, char** argv) {
    
    
    int lienzo[N][M]{
        {1,1,1},
        {1,1,0},
        {1,0,1},
    };
    
    
    int xIni= 1;
    int yIni= 1;
    int colorIni= lienzo[xIni][yIni];
    int colorNuevo= 2;
    funcionPaint(lienzo,xIni,yIni,colorNuevo,colorIni,N,M);
            
    for (int i = 0; i < N; i++) {
        for (int k = 0; k < M; k++) {
            cout<<lienzo[i][k]<<" ";
        }
        cout<<endl;
    }
 
    return 0;
}

