/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: 00123
 *
 * Created on 2 de mayo de 2025, 03:54 PM
 */

#include <iostream>
#include <cmath>

using namespace std;
#define N 6
int matriz[N][N]{
    {1,2,9,1,2,3},
    {5,1,7,0,2,1},
    {0,7,0,3,8,1},
    {1,2,6,1,2,2},
    {0,6,9,5,0,5},
    {0,0,4,0,9,0}
};

int buscarMax(int x,int y,int mx,int my,int n,int &filaMayor){
    
    if(x==N-1 and y==0)return 0;
    if(y==n){
        x++;
        y=n-1;
        mx=1;
        my=0;
    }
    if(x==N)return 0;
    int peso=matriz[x][y]+buscarMax(x+mx,y+my,mx,my,n,filaMayor);
    
    if(y==0){
        if(peso>filaMayor)filaMayor=peso;
        buscarMax(x+1,y,mx,my,n-1,filaMayor);
    }
    
    if(y!=0) return peso;
}


int main(int argc, char** argv) {

    int filaMax=-1,x=0,y=0,mx=0,my=1,filaMayor=-1;
    buscarMax(x,y,mx,my,N,filaMayor);
    cout<<filaMayor<<endl;
    return 0;
}

