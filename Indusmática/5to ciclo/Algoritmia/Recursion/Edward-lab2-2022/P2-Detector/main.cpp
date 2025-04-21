/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: 00123
 *
 * Created on 19 de abril de 2025, 06:55 PM
 */

#include <iostream>
#include <climits>

using namespace std;
#define N 9
#define M 5

int camino[][M]{
    {0,0,0,0,1},  
    {0,0,0,0,0},  
    {0,0,1,0,0},  
    {0,0,0,0,0},  
    {0,1,1,0,1},  
    {0,1,1,0,1},  
    {1,1,0,1,0},  
    {1,1,1,1,0},  
    {1,0,0,0,0},  
};

//cuidado con int_max
//al sumarle 1 se desborda 

int cruzar(int x,int y){
    
    if(x==N-1 and y==M-1)return 1;
    if(x<0 or y<0 or x>=N or y>=M)return 1000;
    
    if(camino[x][y]==1)return 1000;    
    int a,b,c,menor;
    a=cruzar(x+1,y);
    b=cruzar(x+1,y+1);
    c=cruzar(x,y+1);
    if(a<=b and a<=c)menor=a;
    if(b<=a and b<=c)menor=b;
    if(c<=a and c<=b)menor=c;
    
    return menor+1;
}

int main(int argc, char** argv) {

    int x=0,y=0,min;
    min=cruzar(x,y);
    if(min<0)cout<<"No se pudo"<<endl;
    else cout<<"El robot llega al punto final en "<<min-1<<" pasos"<<endl;
    return 0;
}

