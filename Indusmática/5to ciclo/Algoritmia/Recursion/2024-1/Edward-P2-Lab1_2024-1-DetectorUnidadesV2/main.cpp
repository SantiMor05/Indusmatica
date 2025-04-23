/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: 00123
 *
 * Created on 18 de abril de 2025, 10:57 AM
 */

#include <iostream>

using namespace std;
#define M 6
#define N 6

int matriz[][M]{
    {0, 0, 0, 1, 0, 1},
    {0, 0, 1, 0, 0, 0},
    {0, 1, 0, 0, 0, 1},
    {1, 0, 0 ,0 ,0, 0},
    {0, 1, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 0}  
};

int detector(int x,int y,int n,int m){
    
    if(y<0 or x<0 or m==M or n==N)return 0;
    
    int cant=0;
    for (int i = y; i <m; i++) {
        if(matriz[x][i])cant++;
    }
    for (int i = x; i <n; i++) {
        if(matriz[i][m])cant++;
    }
    for (int i = m; i > y; i--) {
        if(matriz[n][i])cant++;
    }
    for (int i = n; i > x; i--) {
        if(matriz[i][y])cant++;
    }
//    cout<<cant<<endl;
    return cant+detector(x-1,y-1,n+1,m+1);
    
}

int main(int argc, char** argv) {

    int x=3,y=2,primero;
    primero=matriz[x][y];
    cout<<"Hay "<<primero+detector(x-1,y-1,x+1,y+1)<<" unidades encontradas";    
    return 0;
}

